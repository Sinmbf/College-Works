import { Router } from "express";
import { generateOTP, deliverOTPToConsole } from "../../services/auth/otp.js";
import { storeOTP, verifyOTP, deleteOTP, isOTPExpired } from "../../services/auth/otpStore.js";
import { signToken } from "../../services/auth/jwt.js";
import { prisma } from "../../db.js";
import { Role, Language } from "../../generated/prisma/index.js";

const router = Router();


router.post("/send-otp", async (req, res) => {
  const { phoneNumber } = req.body;

  if (!phoneNumber || typeof phoneNumber !== "string") {
    return res.status(400).json({ success: false, message: "Phone number is required" });
  }


  const normalized = phoneNumber.replace(/\s/g, "");
  if (!/^(\+977)?9[6-9]\d{8}$/.test(normalized)) {
    return res.status(400).json({ success: false, message: "Invalid phone number format" });
  }

  const code = generateOTP(6);
  storeOTP(normalized, code);
  deliverOTPToConsole(normalized, code);

  res.status(200).json({
    success: true,
    message: "OTP sent to console (development mode)",

  });
});


router.post("/verify", async (req, res) => {
  const { phoneNumber, otp, name } = req.body;

  if (!phoneNumber || !otp) {
    return res.status(400).json({ success: false, message: "Phone number and OTP are required" });
  }

  const normalized = phoneNumber.replace(/\s/g, "");

  if (isOTPExpired(normalized)) {
    return res.status(401).json({ success: false, message: "OTP expired, please request a new one" });
  }

  if (!verifyOTP(normalized, otp)) {
    return res.status(401).json({ success: false, message: "Invalid OTP" });
  }


  const existing = await prisma.user.findUnique({ where: { phoneNumber: normalized } });

  let user;
  if (existing) {

    user = await prisma.user.update({
      where: { id: existing.id },
      data: { lastLoginAt: new Date() },
    });
  } else {

    const trimmedName = typeof name === "string" ? name.trim() : "";
    if (trimmedName.length < 2 || trimmedName.length > 80) {
      return res.status(400).json({
        success: false,
        message: "Name is required (2–80 characters) on first login",
        code: "NAME_REQUIRED",
      });
    }
    user = await prisma.user.create({
      data: {
        phoneNumber: normalized,
        name: trimmedName,
        role: Role.CITIZEN,
        preferredLanguage: Language.EN,
        lastLoginAt: new Date(),
      },
    });
  }

  console.log(`[Citizen Auth] Phone: ${user.phoneNumber}, ID: ${user.id}`);


  deleteOTP(normalized);


  const token = signToken({
    sub: user.id,
    role: user.role,
    lang: user.preferredLanguage,
    pwd: user.passwordChangedAt ? user.passwordChangedAt.getTime() : null,
  });

  res.status(200).json({
    success: true,
    message: "Verification successful",
    token,
    user: {
      id: user.id,
      type: "citizen",
      phoneNumber: user.phoneNumber,
      name: user.name,
      role: user.role,
      preferredLanguage: user.preferredLanguage,
    },
  });
});

export default router;
