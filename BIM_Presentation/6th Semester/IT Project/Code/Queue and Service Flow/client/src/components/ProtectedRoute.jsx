import { Navigate, useLocation } from "react-router-dom";
import { useAuth } from "../auth/AuthContext";


export default function ProtectedRoute({ children, roles }) {
  const { isAuthenticated, isLoading, user } = useAuth();
  const location = useLocation();

  if (isLoading) {
    return (
      <div className="min-h-[60vh] flex items-center justify-center" role="status" aria-live="polite">
        <div className="flex flex-col items-center gap-3">
          <div className="w-10 h-10 border-4 border-neutral-200 border-t-primary-700 rounded-full animate-spin" />
          <span className="text-sm text-neutral-600">Loading…</span>
        </div>
      </div>
    );
  }

  if (!isAuthenticated) {
    return <Navigate to="/login" replace state={{ from: location }} />;
  }

  if (roles && roles.length > 0) {
    const allowed = roles.map((r) => r.toUpperCase());
    const userRole = (user?.role || "").toUpperCase();
    if (!allowed.includes(userRole)) {
      return <Navigate to="/" replace />;
    }
  }

  return children;
}
