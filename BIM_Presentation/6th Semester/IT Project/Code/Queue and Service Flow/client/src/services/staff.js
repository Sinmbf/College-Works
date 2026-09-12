import api from "./api";


export async function checkInToken(identifier) {
  const { data } = await api.post("/staff/tokens/check-in", { identifier });
  return data;
}


export async function fetchStageQueue(stageId) {
  const { data } = await api.get(`/staff/queues/${stageId}`);
  return data;
}


export async function fetchQueueSummary() {
  const { data } = await api.get("/staff/queues/summary");
  return data;
}


export async function callToken(tokenId) {
  const { data } = await api.post(`/staff/tokens/${tokenId}/call`);
  return data;
}


export async function skipToken(tokenId) {
  const { data } = await api.post(`/staff/tokens/${tokenId}/skip`);
  return data;
}


export async function recallToken(tokenId) {
  const { data } = await api.post(`/staff/tokens/${tokenId}/recall`);
  return data;
}


export async function completeToken(tokenId) {
  const { data } = await api.post(`/staff/tokens/${tokenId}/complete`);
  return data;
}

export async function searchStaffTokens(query) { const { data } = await api.get("/staff/tokens/search", { params: { q: query } }); return data; }
