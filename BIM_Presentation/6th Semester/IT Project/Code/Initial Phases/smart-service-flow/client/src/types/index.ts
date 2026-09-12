export type UserRole = 'CITIZEN' | 'STAFF' | 'ADMIN';
export type LanguagePreference = 'EN' | 'NE';

export interface User {
  id: string;
  fullName: string;
  email: string;
  phone: string;
  role: UserRole;
  preferredLanguage: LanguagePreference;
  isPhoneVerified: boolean;
  isActive: boolean;
  createdAt: string;
  updatedAt: string;
}

export interface AuthResponse {
  success: boolean;
  message: string;
  data: {
    user: Omit<User, 'passwordHash'>;
    token: string;
  };
}

export interface LoginRequest {
  email: string;
  password: string;
}

export interface RegisterRequest {
  fullName: string;
  email: string;
  phone: string;
  password: string;
  preferredLanguage: LanguagePreference;
}

export interface VerifyOtpRequest {
  phone: string;
  otp: string;
}

export interface UpdateLanguageRequest {
  language: LanguagePreference;
}