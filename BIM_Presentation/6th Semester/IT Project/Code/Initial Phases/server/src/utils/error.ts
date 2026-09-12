export class ApiError extends Error {
  public statusCode: number;
  public success: boolean;

  constructor(message: string, statusCode: number = 500) {
    super(message);
    this.statusCode = statusCode;
    this.success = statusCode < 400;
    Error.captureStackTrace(this, this.constructor);
  }
}

export const handlePrismaError = (error: any): ApiError => {
  if (error.code === 'P2002') {
    return new ApiError('Duplicate value violates unique constraint', 409);
  }
  if (error.code === 'P2025') {
    return new ApiError('Record not found', 404);
  }
  return new ApiError('Database error', 500);
};