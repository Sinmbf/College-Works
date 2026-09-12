import api from "./api";


export async function fetchServices(params = {}) {
  const { data } = await api.get("/services", { params });
  return data;
}


export async function fetchServiceById(id) {
  const { data } = await api.get(`/services/${id}`);
  return data;
}
