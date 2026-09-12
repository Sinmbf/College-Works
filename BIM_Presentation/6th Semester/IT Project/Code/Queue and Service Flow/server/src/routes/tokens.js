import { Router } from "express";
import { prisma } from "../db.js";
import { requireAuth } from "../middleware/auth.js";
import { signToken } from "../services/auth/jwt.js";

const router = Router();

const ACTIVE_STATUSES = ["WAITING", "CALLED", "CHECKED_IN", "SERVING"];
const TERMINAL_STATUSES = ["COMPLETED", "CANCELLED", "SKIPPED", "EXPIRED"];

const MAX_TRANSACTION_RETRIES = 5;


function buildTokenPrefix(service) {
  const officeId = service.officeId || "";
  const officeInitial = (
    service.office?.nameEn?.charAt(0) || "X"
  ).toUpperCase();

  const officeTag = officeId.slice(-2).toUpperCase();

  return `${officeInitial}${officeTag}`;
}


async function getNextSequence(tx, tokenPrefix) {
  const existingTokens = await tx.token.findMany({
    where: {
      tokenNumber: {
        startsWith: tokenPrefix,
      },
    },
    select: {
      tokenNumber: true,
    },
  });

  let maxSequence = 0;

  for (const token of existingTokens) {
    const sequencePart = token.tokenNumber.slice(tokenPrefix.length);
    const sequence = Number.parseInt(sequencePart, 10);

    if (Number.isInteger(sequence)) {
      maxSequence = Math.max(maxSequence, sequence);
    }
  }

  return maxSequence + 1;
}


router.post("/", requireAuth, async (req, res) => {
  try {
    const { serviceId } = req.body;


    

    if (!serviceId || typeof serviceId !== "string") {
      return res.status(400).json({
        success: false,
        message: "serviceId is required",
      });
    }


    

    const service = await prisma.service.findUnique({
      where: {
        id: serviceId,
      },
      include: {
        office: {
          select: {
            nameEn: true,
          },
        },
      },
    });

    if (!service || !service.isActive) {
      return res.status(404).json({
        success: false,
        message: "Service not found",
      });
    }


    

    const entryStage = await prisma.serviceStage.findFirst({
      where: {
        serviceId,
        stageOrder: 1,
      },
      orderBy: {
        stageOrder: "asc",
      },
    });

    if (!entryStage) {
      return res.status(400).json({
        success: false,
        message: "Service has no entry stage",
      });
    }


    

    let result = null;

    for (let attempt = 1; attempt <= MAX_TRANSACTION_RETRIES; attempt += 1) {
      try {
        result = await prisma.$transaction(
          async (tx) => {

            

            const activeToken = await tx.token.findFirst({
              where: {
                userId: req.user.id,
                status: {
                  in: ACTIVE_STATUSES,
                },
              },
              include: {
                service: {
                  select: {
                    id: true,
                    nameEn: true,
                    nameNe: true,
                  },
                },
              },
              orderBy: {
                generatedAt: "desc",
              },
            });

            if (activeToken) {
              const error = new Error("ACTIVE_TOKEN_EXISTS");

              error.code = "ACTIVE_TOKEN_EXISTS";
              error.activeToken = activeToken;

              throw error;
            }


            

            const activeCount = await tx.token.count({
              where: {
                serviceId,
                currentStageId: entryStage.id,
                status: {
                  in: ACTIVE_STATUSES,
                },
              },
            });

            const nextPosition = activeCount + 1;


            

            const tokenPrefix = buildTokenPrefix(service);

            const nextSequence = await getNextSequence(tx, tokenPrefix);

            const tokenNumber = `${tokenPrefix}${String(nextSequence).padStart(
              3,
              "0",
            )}`;


            

            const generatedAt = new Date();

            const token = await tx.token.create({
              data: {
                tokenNumber,
                userId: req.user.id,
                serviceId,
                currentStageId: entryStage.id,
                position: nextPosition,
                status: "WAITING",
                generatedAt,
                stageEnteredAt: generatedAt,
                qrPayload: Buffer.from(`${tokenNumber}:${serviceId}`).toString(
                  "base64",
                ),
              },
              include: {
                service: true,
                currentStage: true,
              },
            });

            return {
              token,
              tokenNumber,
              position: nextPosition,
            };
          },
          {
            isolationLevel: "Serializable",
          },
        );


        break;
      } catch (innerError) {

        

        if (innerError.code === "ACTIVE_TOKEN_EXISTS") {
          return res.status(409).json({
            success: false,
            code: "ACTIVE_TOKEN_EXISTS",
            message:
              "You already have an active token. Please complete or cancel it first.",
            activeToken: innerError.activeToken,
          });
        }


        

        

        

        
        if (innerError.code === "P2034") {
          console.warn(
            `[POST /api/tokens] transaction conflict. Retry ${attempt}/${MAX_TRANSACTION_RETRIES}`,
          );

          if (attempt < MAX_TRANSACTION_RETRIES) {
            continue;
          }

          console.error(
            "[POST /api/tokens] transaction conflict after retries:",
            innerError,
          );

          return res.status(409).json({
            success: false,
            code: "TOKEN_CONCURRENCY_CONFLICT",
            message:
              "The queue was updated by another request. Please try again.",
          });
        }


        

        

        

        if (innerError.code === "P2002") {
          console.warn(
            `[POST /api/tokens] token-number collision. Retry ${attempt}/${MAX_TRANSACTION_RETRIES}`,
          );

          if (attempt < MAX_TRANSACTION_RETRIES) {
            continue;
          }

          console.error(
            "[POST /api/tokens] unique constraint after retries:",
            innerError,
          );

          return res.status(409).json({
            success: false,
            code: "TOKEN_NUMBER_CONFLICT",
            message:
              "Could not reserve a unique token number. Please try again.",
          });
        }


        throw innerError;
      }
    }


    

    if (!result) {
      return res.status(500).json({
        success: false,
        message: "Failed to generate token",
      });
    }

    const { token, tokenNumber, position } = result;


    

    const activeCounters = await prisma.counter.count({ where: { stageId: token.currentStageId, isActive: true } });
    const activeBusy = await prisma.token.count({ where: { currentStageId: token.currentStageId, status: { in: ["CALLED", "CHECKED_IN", "SERVING"] } } });
    const waitingAhead = token.status === "WAITING" ? await prisma.token.count({ where: { currentStageId: token.currentStageId, status: "WAITING", position: { lt: token.position } } }) : 0;
    const baselineMinutes = Math.max(1, token.currentStage?.baselineMinutes || 10);
    const estimatedWaitMinutes = token.status === "CALLED" || token.status === "CHECKED_IN" || token.status === "SERVING" ? 0 : Math.max(0, Math.ceil((waitingAhead + activeBusy) / Math.max(1, activeCounters)) * baselineMinutes);

    const baseUrl = process.env.CLIENT_URL || "http://localhost:5173";

    const signature = signToken({
      tokenId: token.id,
      sub: req.user.id,
    });

    const qrPayload = `${baseUrl}/verify/${token.id}?sig=${signature}`;


    

    return res.status(201).json({
      success: true,
      message: "Token generated",
      token: {
        id: token.id,
        tokenNumber,
        position,
        status: token.status,
        serviceId: token.serviceId,
        serviceNameEn: service.nameEn,
        currentStageId: token.currentStageId,
        generatedAt: token.generatedAt,
      },
      qrPayload,
    });
  } catch (err) {

    

    if (err.code === "ACTIVE_TOKEN_EXISTS") {
      return res.status(409).json({
        success: false,
        code: "ACTIVE_TOKEN_EXISTS",
        message:
          "You already have an active token. Please complete or cancel it first.",
        activeToken: err.activeToken,
      });
    }

    if (err.code === "P2002") {
      console.error("[POST /api/tokens] unique constraint error:", err);

      return res.status(409).json({
        success: false,
        code: "TOKEN_NUMBER_CONFLICT",
        message: "Token number already exists. Please try again.",
      });
    }

    if (err.code === "P2034") {
      console.error("[POST /api/tokens] transaction conflict:", err);

      return res.status(409).json({
        success: false,
        code: "TOKEN_CONCURRENCY_CONFLICT",
        message: "The queue was updated by another request. Please try again.",
      });
    }

    console.error("[POST /api/tokens] error:", err);

    return res.status(500).json({
      success: false,
      message: "Failed to generate token",
    });
  }
});


router.get("/", requireAuth, async (req, res) => {
  try {
    const mine = req.query.mine === "true" || req.query.mine === "1";

    const all = req.query.all === "true" || req.query.all === "1";

    if (!mine) {
      return res.status(400).json({
        success: false,
        message: "Only mine=true is supported",
      });
    }

    const where = {
      userId: req.user.id,
    };

    if (!all) {
      where.status = {
        in: ACTIVE_STATUSES,
      };
    }

    const tokens = await prisma.token.findMany({
      where,
      include: {
        service: {
          select: {
            id: true,
            nameEn: true,
            nameNe: true,
            _count: { select: { stages: true } },
          },
        },
        currentStage: {
          select: {
            id: true,
            stageOrder: true,
            nameEn: true,
            nameNe: true,
          },
        },
      },
      orderBy: {
        generatedAt: "desc",
      },
      take: 25,
    });

    return res.status(200).json({
      success: true,
      tokens,
    });
  } catch (err) {
    console.error("[GET /api/tokens] error:", err);

    return res.status(500).json({
      success: false,
      message: "Failed to load tokens",
    });
  }
});


router.post("/:id/cancel", requireAuth, async (req, res) => {
  try {
    const token = await prisma.token.findUnique({
      where: {
        id: req.params.id,
      },
      include: {
        user: {
          select: {
            id: true,
            role: true,
          },
        },
      },
    });

    if (!token) {
      return res.status(404).json({
        success: false,
        message: "Token not found",
      });
    }

    const allowedRoles = ["STAFF", "ADMIN"];

    const isOwn = token.userId === req.user.id;

    const isStaff = allowedRoles.includes(req.user.role);

    if (!isOwn && !isStaff) {
      return res.status(403).json({
        success: false,
        message: "Not authorized",
      });
    }

    if (TERMINAL_STATUSES.includes(token.status)) {
      return res.status(400).json({
        success: false,
        message: "Token is already terminal",
      });
    }

    await prisma.token.update({
      where: {
        id: req.params.id,
      },
      data: {
        status: "CANCELLED",
        cancelledAt: new Date(),
      },
    });

    return res.status(200).json({
      success: true,
      message: "Token cancelled",
    });
  } catch (err) {
    console.error("[POST /api/tokens/:id/cancel] error:", err);

    return res.status(500).json({
      success: false,
      message: "Failed to cancel token",
    });
  }
});


router.get("/:id", requireAuth, async (req, res) => {
  try {
    const token = await prisma.token.findUnique({
      where: {
        id: req.params.id,
      },
      include: {
        currentStage: true,
        service: {
          select: {
            id: true,
            nameEn: true,
            nameNe: true,
          },
        },
        user: {
          select: {
            id: true,
            name: true,
            phoneNumber: true,
            role: true,
          },
        },
      },
    });

    if (!token) {
      return res.status(404).json({
        success: false,
        message: "Token not found",
      });
    }

    const allowedRoles = ["STAFF", "ADMIN"];

    const isOwn = token.userId === req.user.id;

    const isStaff = allowedRoles.includes(req.user.role);

    if (!isOwn && !isStaff) {
      return res.status(403).json({
        success: false,
        message: "Not authorized for this token",
      });
    }


    
    const baseUrl = process.env.CLIENT_URL || "http://localhost:5173";

    const signature = signToken({
      tokenId: token.id,
      sub: token.userId,
    });

    const qrPayload = `${baseUrl}/verify/${token.id}?sig=${signature}`;


    
    const activeCounters = token.currentStage
      ? await prisma.counter.count({
          where: {
            stageId: token.currentStage.id,
            isActive: true,
          },
        })
      : 0;

    const activeBusy = token.currentStage
      ? await prisma.token.count({
          where: {
            currentStageId: token.currentStage.id,
            status: { in: ["CALLED", "CHECKED_IN", "SERVING"] },
          },
        })
      : 0;

    const waitingAhead =
      token.status === "WAITING" && token.currentStage
        ? await prisma.token.count({
            where: {
              currentStageId: token.currentStage.id,
              status: "WAITING",
              OR: [
                { stageEnteredAt: { lt: token.stageEnteredAt } },
                { stageEnteredAt: token.stageEnteredAt, id: { lt: token.id } },
              ],
            },
          })
        : 0;

    const currentQueuePosition =
      token.status === "WAITING"
        ? waitingAhead + 1
        : token.position;

    const baselineMinutes = Math.max(
      1,
      token.currentStage?.baselineMinutes || 10,
    );

    const estimatedWaitMinutes =
      token.status === "CALLED" ||
      token.status === "CHECKED_IN" ||
      token.status === "SERVING"
        ? 0
        : token.currentStage
          ? Math.max(
              0,
              Math.ceil(
                (waitingAhead + activeBusy) / Math.max(1, activeCounters),
              ) * baselineMinutes,
            )
          : 0;

    return res.status(200).json({
      success: true,
      token: {
        id: token.id,
        tokenNumber: token.tokenNumber,
        position: currentQueuePosition,
        status: token.status,
        service: {
          id: token.service.id,
          nameEn: token.service.nameEn,
          nameNe: token.service.nameNe,
        },
        currentStage: token.currentStage
          ? {
              id: token.currentStage.id,
              stageOrder: token.currentStage.stageOrder,
              nameEn: token.currentStage.nameEn,
              nameNe: token.currentStage.nameNe,
            }
          : null,
        user: token.user,
        generatedAt: token.generatedAt,
        checkedInAt: token.checkedInAt,
        estimatedWaitMinutes,
        waitingAhead,
        activeCounters,
        baselineMinutes,
        qrPayload,
        completedAt: token.completedAt,
      },
    });
  } catch (err) {
    console.error("[GET /api/tokens/:id] error:", err);

    return res.status(500).json({
      success: false,
      message: "Failed to load token",
    });
  }
});

export default router;



