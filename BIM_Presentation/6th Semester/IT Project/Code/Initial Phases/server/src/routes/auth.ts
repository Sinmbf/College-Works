import express, { Request, Response, NextFunction } from "express";
import { PrismaClient, UserRole, LanguagePreference } from "@prisma/client";
import bcrypt from "bcryptjs";
import jwt from "jsonwebtoken";
import { body, validationResult } from "express-validator";

const router = express.Router();
const prisma = new PrismaClient();

/* -------------------------------------------------------------------------- */
/*                               VALIDATIONS                                  */
/* -------------------------------------------------------------------------- */

export const registerValidation = [
  body("fullName")
    .trim()
    .isLength({ min: 2 })
    .withMessage("Full name must be at least 2 characters"),

  body("email")
    .isEmail()
    .normalizeEmail()
    .withMessage("Valid email is required"),

  body("phone")
    .matches(/^[0-9]{10}$/)
    .withMessage("Phone number must contain exactly 10 digits"),

  body("password")
    .isLength({ min: 6 })
    .withMessage("Password must be at least 6 characters"),

  body("preferredLanguage")
    .isIn(["EN", "NE"])
    .withMessage("Preferred language must be EN or NE"),
];

export const loginValidation = [
  body("email")
    .isEmail()
    .normalizeEmail()
    .withMessage("Valid email is required"),

  body("password")
    .notEmpty()
    .withMessage("Password is required"),
];

/* -------------------------------------------------------------------------- */
/*                                HELPERS                                     */
/* -------------------------------------------------------------------------- */

const JWT_SECRET = process.env.JWT_SECRET || "development_secret";

const generateToken = (userId: string, role: UserRole) => {
  return jwt.sign(
    { userId, role },
    JWT_SECRET,
    {
      expiresIn: process.env.JWT_EXPIRES_IN || "7d",
    }
  );
};

const hashPassword = async (password: string) => {
  return bcrypt.hash(password, 10);
};

const comparePassword = async (
  password: string,
  hash: string
) => {
  return bcrypt.compare(password, hash);
};

/* -------------------------------------------------------------------------- */
/*                           AUTH MIDDLEWARE                                  */
/* -------------------------------------------------------------------------- */

interface AuthRequest extends Request {
  user?: {
    userId: string;
    role: UserRole;
  };
}

const authenticateToken = (
  req: AuthRequest,
  res: Response,
  next: NextFunction
) => {
  const authHeader = req.headers.authorization;

  if (!authHeader) {
    return res.status(401).json({
      success: false,
      message: "Access token missing",
    });
  }

  const token = authHeader.split(" ")[1];

  if (!token) {
    return res.status(401).json({
      success: false,
      message: "Invalid authorization header",
    });
  }

  try {
    const decoded = jwt.verify(token, JWT_SECRET) as {
      userId: string;
      role: UserRole;
    };

    req.user = decoded;

    next();
  } catch {
    return res.status(401).json({
      success: false,
      message: "Invalid or expired token",
    });
  }
};

/* -------------------------------------------------------------------------- */
/*                          ROLE AUTHORIZATION                                */
/* -------------------------------------------------------------------------- */

const authorizeRoles =
  (...roles: UserRole[]) =>
  (
    req: AuthRequest,
    res: Response,
    next: NextFunction
  ) => {
    if (!req.user) {
      return res.status(401).json({
        success: false,
        message: "Unauthorized",
      });
    }

    if (!roles.includes(req.user.role)) {
      return res.status(403).json({
        success: false,
        message: "Permission denied",
      });
    }

    next();
  };


/* -------------------------------------------------------------------------- */
/*                           CITIZEN REGISTRATION                             */
/* -------------------------------------------------------------------------- */

router.post(
  "/register",
  registerValidation,
  async (req: Request, res: Response) => {
    const errors = validationResult(req);

    if (!errors.isEmpty()) {
      return res.status(400).json({
        success: false,
        message: errors.array().map(err => err.msg).join(", "),
      });
    }

    try {
      const {
        fullName,
        email,
        phone,
        password,
        preferredLanguage,
      } = req.body;

      // Check existing email
      const emailExists = await prisma.user.findUnique({
        where: { email },
      });

      if (emailExists) {
        return res.status(409).json({
          success: false,
          message: "Email already registered.",
        });
      }

      // Check existing phone
      const phoneExists = await prisma.user.findUnique({
        where: { phone },
      });

      if (phoneExists) {
        return res.status(409).json({
          success: false,
          message: "Phone number already registered.",
        });
      }

      // Hash password
      const passwordHash = await hashPassword(password);

      // Create citizen
      const user = await prisma.user.create({
        data: {
          fullName,
          email,
          phone,
          passwordHash,
          role: UserRole.CITIZEN,
          preferredLanguage:
            preferredLanguage === "NE"
              ? LanguagePreference.NE
              : LanguagePreference.EN,
        },
      });

      // Generate 6-digit OTP
      const otp = Math.floor(
        100000 + Math.random() * 900000
      ).toString();

      const otpHash = await bcrypt.hash(otp, 10);

      // Remove any previous OTP
      await prisma.otpVerification.deleteMany({
        where: {
          userId: user.id,
          verifiedAt: null,
        },
      });

      // Save OTP
      await prisma.otpVerification.create({
        data: {
          userId: user.id,
          otpHash,
          expiresAt: new Date(Date.now() + 5 * 60 * 1000),
        },
      });

      // TEMPORARY
      // Replace with SMS provider later.
      console.log(
        `OTP for ${user.phone}: ${otp}`
      );

      return res.status(201).json({
        success: true,
        message:
          "Registration successful. Verify your phone using the OTP sent.",
        data: {
          id: user.id,
          fullName: user.fullName,
          email: user.email,
          phone: user.phone,
          preferredLanguage: user.preferredLanguage,
        },
      });

    } catch (error) {

      console.error("Registration Error:", error);

      return res.status(500).json({
        success: false,
        message: "Internal server error.",
      });

    }
  }
);