import { prisma } from "../../db.js";

const DEFAULT_INTERVAL_MS = 10_000;
const DEFAULT_APPROACH_MINUTES = 10;
let handle = null;
let processing = false;

function envNumber(name, fallback) {
  const n = Number(process.env[name]);
  return Number.isFinite(n) && n > 0 ? n : fallback;
}

async function createNotification(tx, { token, type, counterName, stage, minutes }) {
  const approaching = type === "TURN_APPROACHING";
  const nepali = token.user?.preferredLanguage === "NE";
  const grace = envNumber("NO_SHOW_MINUTES", 3);
  const place = counterName || stage.location || (nepali ? "सेवा काउन्टर" : "service counter");

  await tx.notification.create({
    data: {
      userId: token.userId,
      tokenId: token.id,
      type,
      titleEn: approaching ? "Your turn is approaching" : "Your turn has come",
      titleNe: approaching ? "तपाईंको पालो आउँदैछ" : "तपाईंको पालो आएको छ",
      messageEn: approaching
        ? `Your turn is about ${minutes} minutes away. Please be ready to proceed to ${place}.`
        : `Your turn has come. Please proceed to ${place} within the next ${grace} minutes.`,
      messageNe: approaching
        ? `तपाईंको पालो करिब ${minutes} मिनेटमा आउँछ। ${place} मा जान तयार रहनुहोस्।`
        : `तपाईंको पालो आएको छ। कृपया ${grace} मिनेटभित्र ${place} मा जानुहोस्।`,
    },
  });
}

export async function processQueueAutomation({ now = new Date() } = {}) {
  if (processing) return;
  processing = true;
  try {
    const approachMinutes = envNumber("TURN_APPROACHING_MINUTES", DEFAULT_APPROACH_MINUTES);
    const stages = await prisma.serviceStage.findMany({
      where: { tokens: { some: { status: { in: ["WAITING", "CALLED", "CHECKED_IN", "SERVING"] } } } },
      select: {
        id: true,
        serviceId: true,
        nameEn: true,
        baselineMinutes: true,
        location: true,
        counters: {
          orderBy: { name: "asc" },
          select: { id: true, name: true, isActive: true, currentTokenId: true },
        },
      },
    });

    for (const stage of stages) {

      

      
      if (stage.counters.length === 0) {
        const fallbackName = stage.location?.match(/Counter\s+\d+(?:\s*-\s*\d+)?/i)?.[0] || "Primary Counter";
        try {
          await prisma.counter.create({
            data: {
              stageId: stage.id,
              name: `${stage.location ? stage.location.replace(/,?\s*Counter\s+\d+\s*-\s*\d+/i, "").trim() : stage.nameEn} — ${fallbackName}`,
              isActive: true,
            },
          });
        } catch (err) {

          console.warn(`[queue/autoCall] counter bootstrap for stage ${stage.id}: ${err?.message || err}`);
        }
        stage.counters = await prisma.counter.findMany({
          where: { stageId: stage.id },
          orderBy: { name: "asc" },
          select: { id: true, name: true, isActive: true, currentTokenId: true },
        });
      }


      

      
      stage.counters = await prisma.counter.findMany({
        where: { stageId: stage.id },
        orderBy: { name: "asc" },
        select: { id: true, name: true, isActive: true, currentTokenId: true },
      });

      const referencedTokenIds = stage.counters
        .map((counter) => counter.currentTokenId)
        .filter(Boolean);

      if (referencedTokenIds.length) {
        const referencedTokens = await prisma.token.findMany({
          where: { id: { in: referencedTokenIds } },
          select: { id: true, currentStageId: true, status: true },
        });
        const validById = new Map(
          referencedTokens
            .filter((token) =>
              token.currentStageId === stage.id &&
              ["CALLED", "CHECKED_IN", "SERVING"].includes(token.status),
            )
            .map((token) => [token.id, token]),
        );

        const staleCounterIds = stage.counters
          .filter((counter) => counter.currentTokenId && !validById.has(counter.currentTokenId))
          .map((counter) => counter.id);

        if (staleCounterIds.length) {
          await prisma.counter.updateMany({
            where: { id: { in: staleCounterIds } },
            data: { currentTokenId: null },
          });
          stage.counters = await prisma.counter.findMany({
            where: { stageId: stage.id },
            orderBy: { name: "asc" },
            select: { id: true, name: true, isActive: true, currentTokenId: true },
          });
          console.log(
            `[queue/autoCall] released ${staleCounterIds.length} stale counter pointer(s) for stage ${stage.id}`
          );
        }
      }

      const activeCounters = stage.counters.filter((c) => c.isActive);
      const capacity = activeCounters.length;
      if (capacity < 1) continue;


      

      const called = await prisma.token.findMany({
        where: { currentStageId: stage.id, status: "CALLED" },
        orderBy: [{ calledAt: "asc" }, { stageEnteredAt: "asc" }, { generatedAt: "asc" }, { id: "asc" }],
        select: { id: true, calledAt: true },
      });
      if (called.length > capacity) {
        const duplicateIds = called.slice(capacity).map((t) => t.id);
        await prisma.$transaction(async (tx) => {
          await tx.token.updateMany({
            where: { id: { in: duplicateIds }, status: "CALLED" },
            data: { status: "WAITING", calledAt: null, turnApproachingNotifiedAt: null },
          });
          await tx.counter.updateMany({
            where: { currentTokenId: { in: duplicateIds } },
            data: { currentTokenId: null },
          });
          for (const id of duplicateIds) {
            await tx.auditLog.create({
              data: {
                action: "TOKEN_CALL_RECONCILED",
                target: id,
                metadata: { stageId: stage.id, reason: "active_calls_exceeded_counter_capacity" },
              },
            });
          }
        });
      }

      const activeTokens = await prisma.token.findMany({
        where: { currentStageId: stage.id, status: { in: ["CALLED", "CHECKED_IN", "SERVING"] } },
        orderBy: [{ calledAt: "asc" }, { serviceStartedAt: "asc" }, { stageEnteredAt: "asc" }, { generatedAt: "asc" }, { id: "asc" }],
        select: { id: true, status: true },
      });


      

      let counterSnapshot = stage.counters.filter((c) => c.isActive);
      const assignedTokenIds = new Set(
        counterSnapshot.map((counter) => counter.currentTokenId).filter(Boolean),
      );
      const unassignedActive = activeTokens.filter((token) => !assignedTokenIds.has(token.id));
      const freeForReassignment = counterSnapshot.filter((counter) => !counter.currentTokenId);

      if (unassignedActive.length && freeForReassignment.length) {
        const repairCount = Math.min(unassignedActive.length, freeForReassignment.length);
        for (let i = 0; i < repairCount; i += 1) {
          await prisma.counter.update({
            where: { id: freeForReassignment[i].id },
            data: { currentTokenId: unassignedActive[i].id },
          });
        }
        stage.counters = await prisma.counter.findMany({
          where: { stageId: stage.id },
          orderBy: { name: "asc" },
          select: { id: true, name: true, isActive: true, currentTokenId: true },
        });
        counterSnapshot = stage.counters.filter((c) => c.isActive);
      }

      const availableCounters = counterSnapshot;
      const busySlots = Math.min(activeTokens.length, capacity);
      const freeSlots = Math.max(0, capacity - busySlots);

      const waiting = await prisma.token.findMany({
        where: { currentStageId: stage.id, status: "WAITING" },
        orderBy: [{ stageEnteredAt: "asc" }, { generatedAt: "asc" }, { id: "asc" }],
        select: {
          id: true,
          tokenNumber: true,
          userId: true,
          position: true,
          turnApproachingNotifiedAt: true,
          user: { select: { id: true, preferredLanguage: true } },
        },
      });
      if (!waiting.length) continue;

      const baseline = Math.max(1, stage.baselineMinutes || 10);

      if (freeSlots > 0) {

        

        const sortedFreeCounters = availableCounters
          .filter((c) => !c.currentTokenId)
          .slice(0, freeSlots);
        const callCandidates = waiting.slice(0, sortedFreeCounters.length);

        for (let i = 0; i < callCandidates.length; i += 1) {
          const candidate = callCandidates[i];
          const counter = sortedFreeCounters[i];

          await prisma.$transaction(async (tx) => {
            const current = await tx.token.findUnique({
              where: { id: candidate.id },
              include: { user: { select: { id: true, preferredLanguage: true } } },
            });
            if (!current || current.status !== "WAITING") return;

            const activeNow = await tx.token.count({
              where: { currentStageId: stage.id, status: { in: ["CALLED", "CHECKED_IN", "SERVING"] } },
            });
            if (activeNow >= capacity) return;

            const free = await tx.counter.findFirst({
              where: { id: counter.id, isActive: true, currentTokenId: null },
            });
            if (!free) return;

            await tx.token.update({ where: { id: current.id }, data: { status: "CALLED", calledAt: now } });
            await tx.counter.update({ where: { id: free.id }, data: { currentTokenId: current.id } });
            await createNotification(tx, {
              token: current,
              type: "TOKEN_CALLED",
              counterName: free.name,
              stage,
              minutes: 0,
            });
            await tx.auditLog.create({
              data: {
                action: "TOKEN_CALLED",
                target: current.id,
                metadata: { stageId: stage.id, counterId: free.id, counterName: free.name },
              },
            });
          });
        }
      }


      

      const calledThisCycleIds = new Set(
        waiting
          .slice(0, Math.max(0, freeSlots))
          .map((token) => token.id),
      );
      const remainingWaiting = await prisma.token.findMany({
        where: { currentStageId: stage.id, status: "WAITING" },
        orderBy: [{ stageEnteredAt: "asc" }, { generatedAt: "asc" }, { id: "asc" }],
        select: {
          id: true,
          userId: true,
          turnApproachingNotifiedAt: true,
          user: { select: { id: true, preferredLanguage: true } },
        },
      });

      const currentActiveCount = await prisma.token.count({
        where: { currentStageId: stage.id, status: { in: ["CALLED", "CHECKED_IN", "SERVING"] } },
      });

      for (let i = 0; i < remainingWaiting.length; i += 1) {
        const token = remainingWaiting[i];
        if (calledThisCycleIds.has(token.id)) continue;
        const estimated = Math.max(
          1,
          Math.ceil((currentActiveCount + i) / Math.max(1, capacity)) * baseline,
        );

        if (!token.turnApproachingNotifiedAt && estimated <= approachMinutes) {
          await prisma.$transaction(async (tx) => {
            const current = await tx.token.findUnique({
              where: { id: token.id },
              select: { status: true, turnApproachingNotifiedAt: true, userId: true },
            });
            if (!current || current.status !== "WAITING" || current.turnApproachingNotifiedAt) return;

            await tx.token.update({
              where: { id: token.id },
              data: { turnApproachingNotifiedAt: now },
            });
            await createNotification(tx, {
              token: { ...token, userId: current.userId },
              type: "TURN_APPROACHING",
              stage,
              minutes: Math.max(1, estimated),
            });
            await tx.auditLog.create({
              data: {
                action: "TURN_APPROACHING_NOTIFIED",
                target: token.id,
                metadata: { estimatedWaitMinutes: estimated, stageId: stage.id },
              },
            });
          });
        }
      }
    }
  } finally {
    processing = false;
  }
}

export function startQueueAutomation() {
  if (handle) return;
  processQueueAutomation().catch((err) => console.error("[queue/autoCall] initial run failed:", err));
  const interval = envNumber("QUEUE_AUTOMATION_INTERVAL_MS", DEFAULT_INTERVAL_MS);
  handle = setInterval(() => {
    processQueueAutomation().catch((err) => console.error("[queue/autoCall] run failed:", err));
  }, interval);
  handle.unref?.();
  console.log(`[queue/autoCall] started (interval ${interval}ms)`);
}

export function stopQueueAutomation() {
  if (handle) {
    clearInterval(handle);
    handle = null;
  }
}
