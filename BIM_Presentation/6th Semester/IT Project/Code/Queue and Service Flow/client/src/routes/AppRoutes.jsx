import { useEffect } from "react";
import { BrowserRouter, Routes, Route, Navigate, useLocation } from "react-router-dom";
import { Login, Register, VerifyPhone, ForgotPassword, ResetPassword, CitizenOTP, StaffRegister } from "../pages/auth";
import Home from "../pages/Home";
import Dashboard from "../pages/Dashboard";
import StaffDashboard from "../pages/StaffDashboard";
import ServiceList from "../pages/services/ServiceList";
import ServiceDetail from "../pages/services/ServiceDetail";
import { QRScanner, ServiceSelection, TokenGeneration, TokenDisplay, Monitor } from "../pages/token";
import CheckIn from "../pages/staff/CheckIn";
import QueueBoard from "../pages/staff/QueueBoard";
import Notifications from "../pages/Notifications";
import ProtectedRoute from "../components/ProtectedRoute";
import { useAuth } from "../auth/AuthContext";



function ScrollToTop() {
  const { pathname } = useLocation();

  useEffect(() => {
    window.scrollTo({ top: 0, left: 0, behavior: "instant" });
  }, [pathname]);

  return null;
}


function SmartRedirect({ children }) {
  const { isAuthenticated, isLoading, user } = useAuth();
  const location = useLocation();

  if (isLoading) return null;

  if (isAuthenticated) {
    const role = (user?.role || "").toUpperCase();
    if (role === "STAFF" || role === "ADMIN") {
      return <Navigate to="/staff/dashboard" replace />;
    }
    return <Navigate to="/dashboard" replace />;
  }


  

  return <div data-from={location.state?.from?.pathname}>{children}</div>;
}

function AppRoutes() {
  return (
    <BrowserRouter>
      <ScrollToTop />
      <Routes>

        <Route path="/" element={<Home />} />


        

        <Route path="/login" element={<SmartRedirect><Login /></SmartRedirect>} />
        <Route path="/citizen-login" element={<CitizenOTP />} />
        <Route path="/staff-register" element={<StaffRegister />} />
        <Route path="/register" element={<Register />} />
        <Route path="/verify-phone" element={<VerifyPhone />} />
        <Route path="/forgot-password" element={<ForgotPassword />} />
        <Route path="/reset-password" element={<ResetPassword />} />


        <Route
          path="/notifications"
          element={
            <ProtectedRoute roles={["CITIZEN"]}>
              <Notifications />
            </ProtectedRoute>
          }
        />

        <Route
          path="/dashboard"
          element={
            <ProtectedRoute roles={["CITIZEN"]}>
              <Dashboard />
            </ProtectedRoute>
          }
        />
        <Route
          path="/staff/dashboard"
          element={
            <ProtectedRoute roles={["STAFF", "ADMIN"]}>
              <StaffDashboard />
            </ProtectedRoute>
          }
        />
        <Route
          path="/staff/check-in"
          element={
            <ProtectedRoute roles={["STAFF", "ADMIN"]}>
              <CheckIn />
            </ProtectedRoute>
          }
        />
        <Route
          path="/staff/queues/:stageId"
          element={
            <ProtectedRoute roles={["STAFF", "ADMIN"]}>
              <QueueBoard />
            </ProtectedRoute>
          }
        />


        <Route path="/services" element={<ServiceList />} />
        <Route path="/services/:id" element={<ServiceDetail />} />


        <Route path="/token/scanner" element={<QRScanner />} />
        <Route path="/token/services" element={<ServiceSelection />} />
        <Route path="/token/generate" element={<TokenGeneration />} />
        <Route path="/token/display/:id" element={<TokenDisplay />} />
        <Route path="/token/display" element={<Navigate to="/dashboard" replace />} />
        <Route path="/token/monitor" element={<Monitor />} />


        <Route path="*" element={<Navigate to="/" replace />} />
      </Routes>
    </BrowserRouter>
  );
}

export default AppRoutes;
