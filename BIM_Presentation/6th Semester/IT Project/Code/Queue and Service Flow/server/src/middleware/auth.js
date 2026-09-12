import { verifyToken } from "../services/auth/jwt.js";
import { prisma } from "../db.js";


export async function requireAuth(req, res, next) {
  const header = req.headers.authorization || "";

  if (!header.startsWith("Bearer ")) {
    return res.status(401).json({ success: false, message: "Missing or malformed Authorization header" });
  }

  const token = header.slice("Bearer ".length).trim();
  const payload = verifyToken(token);

  if (!payload || !payload.sub) {
    return res.status(401).json({ success: false, message: "Invalid or expired token" });
  }


  const user = await prisma.user.findUnique({
    where: { id: payload.sub },
    select: {
      id: true,
      name: true,
      email: true,
      phoneNumber: true,
      employeeId: true,
      role: true,
      preferredLanguage: true,
      isActive: true,
      passwordChangedAt: true,
      officeId: true,
      office: { select: { id: true, nameEn: true, nameNe: true, location: true } },
    },
  });

  if (!user || !user.isActive) {
    return res.status(401).json({ success: false, message: "User not found or deactivated" });
  }


  

  const tokenPwd = typeof payload.pwd === "number" ? payload.pwd : null;
  const currentPwd = user.passwordChangedAt ? user.passwordChangedAt.getTime() : null;
  if (tokenPwd !== currentPwd) {
    return res.status(401).json({
      success: false,
      message: "Token invalidated by password change. Please sign in again.",
    });
  }

  req.user = user;
  next();
}


export function requireRole(...allowed) {
  return (req, res, next) => {
    if (!req.user) {
      return res.status(401).json({ success: false, message: "Authentication required" });
    }

    if (!allowed.includes(req.user.role)) {
      return res.status(403).json({ success: false, message: "Insufficient permissions" });
    }

    next();
  };
}
