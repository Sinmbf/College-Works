
import fs from "node:fs";
import path from "node:path";

export function generateOTP(length = 6) {
  const digits = "0123456789";
  let otp = "";
  for (let i = 0; i < length; i++) {
    otp += digits[Math.floor(Math.random() * digits.length)];
  }
  return otp;
}


export function deliverOTPToConsole(target, code) {
  const targetStr = String(target).padEnd(20);
  const codeStr = String(code).padEnd(20);


  const box = [
    "",
    "┌─────────────────────────────────────┐",
    "│  OTP DELIVERY (Console Mode)        │",
    `│  Target: ${targetStr}    │`,
    `│  Code:   ${codeStr}          │`,
    "│  (In production: send via SMS)       │",
    "└─────────────────────────────────────┘",
    "",
  ].join("\n");
  console.log(box);


  try {
    const timestamp = new Date().toISOString().replace("T", " ").slice(0, 19);
    const logFile = path.join(process.cwd(), "otp.log");
    fs.appendFileSync(logFile, `[OTP]  ${timestamp}  ${target}  →  ${code}\n`);
  } catch (err) {

    console.warn(`[OTP]  (could not write to otp.log: ${err.message})`);
  }
}
