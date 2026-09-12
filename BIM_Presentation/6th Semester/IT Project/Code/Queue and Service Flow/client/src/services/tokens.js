import api from "./api";


export async function generateToken(body) {
  const { data } = await api.post("/tokens", body);
  return data;
}


export async function fetchToken(id) {
  const { data } = await api.get(`/tokens/${id}`);
  return data;
}


export async function fetchMyActiveTokens({ all = false } = {}) {
  const { data } = await api.get("/tokens", { params: { mine: "true", ...(all ? { all: "true" } : {}) } });
  return data;
}


export async function cancelToken(id) {
  const { data } = await api.post(`/tokens/${id}/cancel`);
  return data;
}



export async function fetchNotifications(params) {
  const { data } = await api.get("/notifications", { params });
  return data;
}


export async function markNotificationRead(id) {
  const { data } = await api.post(`/notifications/${id}/read`);
  return data;
}


export async function markAllNotificationsRead() {
  const { data } = await api.post("/notifications/read-all");
  return data;
}


export async function deleteNotification(id) {
  const { data } = await api.delete(`/notifications/${id}`);
  return data;
}


export async function deleteAllNotifications() {
  const { data } = await api.delete("/notifications");
  return data;
}
