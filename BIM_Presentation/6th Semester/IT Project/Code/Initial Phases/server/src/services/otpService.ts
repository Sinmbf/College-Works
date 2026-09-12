import { PrismaClient } from '@prisma/client';
import bcrypt from 'bcryptjs';
import { OtpVerification } from '../prisma/schema';
import { User } from '../prisma/schema';

const prisma = new PrismaClient();

export class OtpService {
  async generateOtp(userId: string): Promise<string> {
    const otp = Math.floor(100000 + Math.random() * 900000).toString();
    const otpHash = await bcrypt.hash(otp, 10);
    const expiresAt = new Date();
    expiresAt.setMinutes(expiresAt.getMinutes() + 5);

    await prisma.otpVerification.upsert({
      where: { userId },
      update: {
        otpHash,
        expiresAt,
        attempts: 0,
      },
      create: {
        userId,
        otpHash,
        expiresAt,
        attempts: 0,
      },
    });

    return otp;
  }

  async verifyOtp(userId: string, otp: string): Promise<boolean> {
    const record = await prisma.otpVerification.findUnique({
      where: { userId },
    });

    if (!record) return false;

    const isValid = await bcrypt.compare(otp, record.otpHash);
    const isNotExpired = new Date() < record.expiresAt;
    const isNotExhausted = record.attempts < 5;

    if (isValid && isNotExpired && isNotExhausted) {
      await prisma.otpVerification.update({
        where: { userId },
        data: {
          verifiedAt: new Date(),
          attempts: record.attempts + 1,
        },
      });
      return true;
    }

    return false;
  }

  async invalidateOtp(userId: string): Promise<void> {
    await prisma.otpVerification.delete({
      where: { userId },
    });
  }

  async getExpiresAt(userId: string): Promise<Date | null> {
    const record = await prisma.otpVerification.findUnique({
      where: { userId },
    });
    return record?.expiresAt ?? null;
  }

  async incrementAttempts(userId: string): Promise<void> {
    await prisma.otpVerification.update({
      where: { userId },
      data: { attempts: { increment: 1 } },
    });
  }

  async resetAttempts(userId: string): Promise<void> {
    await prisma.otpVerification.update({
      where: { userId },
      data: { attempts: 0 },
    });
  }
}