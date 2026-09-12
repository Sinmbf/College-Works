import { useState, useEffect, useMemo, useCallback } from "react";
import { useParams, Link } from "react-router-dom";
import { useTranslation } from "react-i18next";
import {
  Search,
  PhoneCall,
  SkipForward,
  RotateCcw,
  CheckCircle2,
  Users,
  AlertCircle,
  ArrowLeft,
  RefreshCw,
  ListFilter,
  Clock3,
  ChevronLeft,
  ChevronRight,
} from "lucide-react";
import MainLayout from "../../layouts/MainLayout";
import Card from "../../components/ui/Card";
import Button from "../../components/ui/Button";
import {
  fetchStageQueue,
  checkInToken,
  skipToken,
  recallToken,
  completeToken,
} from "../../services/staff";

const POLL_MS = 5000;
const PAGE_SIZE = 25;

function TokenRow({ token, isNe, actions, actionLabels, actionBusyId, tone = "default" }) {
  const toneStyles = {
    default: "bg-white border-neutral-200",
    serving: "bg-primary-50 border-primary-200",
    called: "bg-amber-50 border-amber-200",
    skipped: "bg-neutral-50 border-neutral-200",
  };

  return (
    <div className={`grid grid-cols-[auto_minmax(0,1fr)] sm:grid-cols-[auto_minmax(0,1fr)_auto] items-start sm:items-center gap-3 p-3 sm:p-4 rounded-xl border overflow-hidden ${toneStyles[tone]}`}>
      <div className="flex h-11 w-11 items-center justify-center rounded-lg bg-neutral-100 text-sm font-bold text-neutral-700">
        {token.position ? `#${token.position}` : "—"}
      </div>
      <div className="min-w-0">
        <p className="font-heading font-semibold text-neutral-900 truncate">
          {token.tokenNumber}{" "}
          <span className="font-normal text-neutral-600">— {token.user?.name || (isNe ? "नागरिक" : "Citizen")}</span>
        </p>
        <p className="text-xs text-neutral-500 truncate">
          {token.user?.phoneNumber || (isNe ? "फोन उपलब्ध छैन" : "No phone")}
          {token.estimatedWaitMinutes != null ? ` · ${token.estimatedWaitMinutes} min ETA` : ""}
        </p>
      </div>
      <div className="col-span-2 sm:col-span-1 flex flex-wrap items-center justify-start sm:justify-end gap-2 min-w-0">
        {actions.map(({ key, onClick, icon: Icon, variant }) => (
          <Button
            key={key}
            size="sm"
            variant={variant}
            isLoading={actionBusyId === `${token.id}:${key}`}
            disabled={actionBusyId != null}
            onClick={() => onClick(token.id)}
          >
            <Icon className="h-4 w-4 mr-1" />
            {actionLabels[key]}
          </Button>
        ))}
      </div>
    </div>
  );
}

function EmptyState({ label }) {
  return <div className="rounded-xl border border-dashed border-neutral-300 bg-neutral-50/60 p-6 text-center text-sm text-neutral-500">{label}</div>;
}

function StatusPill({ value, label, tone }) {
  const styles = {
    neutral: "bg-neutral-100 text-neutral-700",
    primary: "bg-primary-100 text-primary-800",
    amber: "bg-amber-100 text-amber-800",
  };
  return <button type="button" className={`rounded-full px-3 py-1.5 text-sm font-semibold ${styles[tone]}`} onClick={() => {}}>{label} <span className="ml-1 opacity-70">{value}</span></button>;
}

const QueueBoard = () => {
  const { stageId } = useParams();
  const { t, i18n } = useTranslation();
  const isNe = i18n.language === "ne";

  const [stage, setStage] = useState(null);
  const [queue, setQueue] = useState({ serving: [], called: [], checkedIn: [], waiting: [], recentlySkipped: [] });
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState("");
  const [actionBusyId, setActionBusyId] = useState(null);
  const [actionError, setActionError] = useState("");
  const [query, setQuery] = useState("");
  const [statusFilter, setStatusFilter] = useState("ALL");
  const [sortBy, setSortBy] = useState("queue");
  const [page, setPage] = useState(1);

  const load = useCallback(async () => {
    try {
      const data = await fetchStageQueue(stageId);
      setStage(data.stage);
      setQueue(data.queue);
      setError("");
    } catch (err) {
      setError(err.response?.data?.message || (isNe ? "क्यू लोड गर्न सकिएन।" : "Failed to load the queue."));
    } finally {
      setLoading(false);
    }
  }, [stageId, isNe]);

  useEffect(() => {
    load();
    const intervalId = setInterval(load, POLL_MS);
    return () => clearInterval(intervalId);
  }, [load]);

  useEffect(() => setPage(1), [query, statusFilter, sortBy]);

  const runAction = async (actionKey, tokenId, fn) => {
    setActionBusyId(`${tokenId}:${actionKey}`);
    setActionError("");
    try {
      await fn(tokenId);
      await load();
    } catch (err) {
      setActionError(err.response?.data?.message || (isNe ? "कार्य असफल भयो।" : "Action failed. Please try again."));
    } finally {
      setActionBusyId(null);
    }
  };

  const combined = useMemo(() => {
    const groups = [
      ...queue.waiting.map((t) => ({ ...t, uiStatus: "WAITING" })),
      ...queue.called.map((t) => ({ ...t, uiStatus: "CALLED" })),
      ...queue.serving.map((t) => ({ ...t, uiStatus: "SERVING" })),
      ...queue.recentlySkipped.map((t) => ({ ...t, uiStatus: "SKIPPED" })),
    ];
    const q = query.trim().toLowerCase();
    return groups
      .filter((token) => statusFilter === "ALL" || token.uiStatus === statusFilter)
      .filter((token) => !q || [token.tokenNumber, token.user?.name, token.user?.phoneNumber].filter(Boolean).some((v) => String(v).toLowerCase().includes(q)))
      .sort((a, b) => {
        if (sortBy === "name") return String(a.user?.name || "").localeCompare(String(b.user?.name || ""));
        if (sortBy === "recent") return new Date(b.generatedAt || 0) - new Date(a.generatedAt || 0);
        return (a.position ?? 999999) - (b.position ?? 999999) || new Date(a.generatedAt || 0) - new Date(b.generatedAt || 0);
      });
  }, [queue, query, statusFilter, sortBy]);

  const pageCount = Math.max(1, Math.ceil(combined.length / PAGE_SIZE));
  const visible = combined.slice((page - 1) * PAGE_SIZE, page * PAGE_SIZE);

  const actionLabels = {
    checkIn: t("staff.queue.checkIn", "Check In & Start"),
    skip: t("staff.queue.skip", "Skip"),
    recall: t("staff.queue.recall", "Recall"),
    complete: t("staff.queue.complete", "Complete"),
  };

  const stageName = stage ? (isNe ? stage.nameNe : stage.nameEn) : "";
  const serviceName = stage ? (isNe ? stage.service?.nameNe : stage.service?.nameEn) : "";
  const counts = {
    waiting: queue.waiting.length,
    called: queue.called.length,
    serving: queue.serving.length,
    skipped: queue.recentlySkipped.length,
  };

  const renderToken = (token) => {
    const actions = token.uiStatus === "SERVING"
      ? [{ key: "complete", icon: CheckCircle2, variant: "success", onClick: (id) => runAction("complete", id, completeToken) }]
      : token.uiStatus === "CALLED"
      ? [
          { key: "checkIn", icon: CheckCircle2, variant: "primary", onClick: (id) => runAction("checkIn", id, checkInToken) },
          { key: "skip", icon: SkipForward, variant: "outline", onClick: (id) => runAction("skip", id, skipToken) },
        ]
      : token.uiStatus === "SKIPPED" && token.recallable !== false
      ? [{ key: "recall", icon: RotateCcw, variant: "secondary", onClick: (id) => runAction("recall", id, recallToken) }]
      : [];
    return <TokenRow key={token.id} token={token} isNe={isNe} tone={token.uiStatus === "SERVING" ? "serving" : token.uiStatus === "CALLED" ? "called" : token.uiStatus === "SKIPPED" ? "skipped" : "default"} actionBusyId={actionBusyId} actionLabels={actionLabels} actions={actions} />;
  };

  return (
    <MainLayout>
      <div className="w-full max-w-7xl mx-auto py-3 sm:py-4 px-1 sm:px-4 overflow-x-hidden">
        <div className="flex flex-col lg:flex-row lg:items-end lg:justify-between gap-4">
          <div>
            <Link to="/staff/dashboard" className="inline-flex items-center gap-1 text-sm text-neutral-500 hover:text-neutral-700 mb-3">
              <ArrowLeft className="h-4 w-4" /> {t("staff.queue.back", "Back to dashboard")}
            </Link>
            <div className="flex items-start sm:items-center gap-2 sm:gap-3 min-w-0">
              <div className="h-10 w-10 rounded-xl bg-primary-100 text-primary-800 flex items-center justify-center"><Users className="h-5 w-5" /></div>
              <div>
                <h1 className="text-xl sm:text-3xl font-heading font-bold text-neutral-900 tracking-tight break-words [overflow-wrap:anywhere]">{stageName || t("staff.queue.title", "Queue Board")}</h1>
                {serviceName && <p className="mt-1 text-sm sm:text-base text-neutral-600 break-words [overflow-wrap:anywhere]">{serviceName}</p>}
              </div>
            </div>
          </div>
          <Button variant="outline" size="sm" className="w-full sm:w-auto" onClick={load} disabled={loading}>
            <RefreshCw className="h-4 w-4 mr-1" /> {t("common.refresh", "Refresh")}
          </Button>
        </div>

        {error && <div className="mt-4 p-4 bg-red-50 border border-red-200 rounded-lg text-sm text-red-700 flex items-start gap-2"><AlertCircle className="h-5 w-5 flex-shrink-0" /><span>{error}</span></div>}
        {actionError && <div className="mt-4 p-4 bg-red-50 border border-red-200 rounded-lg text-sm text-red-700 flex items-start gap-2"><AlertCircle className="h-5 w-5 flex-shrink-0" /><span>{actionError}</span></div>}

        {!loading && (
          <div className="grid grid-cols-2 xl:grid-cols-4 gap-2.5 sm:gap-3 mt-5">
            <Card className="p-4"><div className="text-xs uppercase tracking-wide text-neutral-500 font-semibold">{t("staff.queue.waiting", "Waiting")}</div><div className="mt-1 text-2xl font-heading font-bold text-neutral-900">{counts.waiting}</div></Card>
            <Card className="p-4"><div className="text-xs uppercase tracking-wide text-neutral-500 font-semibold">{t("staff.queue.called", "Called")}</div><div className="mt-1 text-2xl font-heading font-bold text-amber-700">{counts.called}</div></Card>
            <Card className="p-4"><div className="text-xs uppercase tracking-wide text-neutral-500 font-semibold">{t("staff.queue.serving", "Serving")}</div><div className="mt-1 text-2xl font-heading font-bold text-primary-800">{counts.serving}</div></Card>
            <Card className="p-4"><div className="text-xs uppercase tracking-wide text-neutral-500 font-semibold">{t("staff.queue.skipped", "Skipped")}</div><div className="mt-1 text-2xl font-heading font-bold text-neutral-800">{counts.skipped}</div></Card>
          </div>
        )}

        <Card className="mt-5 p-3 sm:p-4 sticky top-2 z-20 shadow-md overflow-visible">
          <div className="flex flex-col gap-3">
            <div className="relative flex-1">
              <Search className="absolute left-3 top-1/2 -translate-y-1/2 h-5 w-5 text-neutral-400" />
              <input value={query} onChange={(e) => setQuery(e.target.value)} placeholder={t("staff.queue.search", "Search token number, citizen name or phone...")} className="w-full min-h-[46px] pl-10 pr-4 border border-neutral-300 rounded-xl bg-white focus:border-primary-500 focus:ring-4 focus:ring-primary-100 outline-none" />
            </div>
            <div className="grid grid-cols-1 sm:grid-cols-[1fr_auto] xl:grid-cols-[1fr_auto] gap-2 items-stretch sm:items-center">
              <div className="grid grid-cols-3 sm:flex rounded-xl bg-neutral-100 p-1 min-w-0">
                {[["ALL", "All"], ["WAITING", "Waiting"], ["CALLED", "Called"], ["SERVING", "Serving"], ["SKIPPED", "Skipped"]].map(([key, label]) => (
                  <button key={key} type="button" onClick={() => setStatusFilter(key)} className={`px-2 sm:px-3 py-2.5 rounded-lg text-sm font-semibold text-center ${statusFilter === key ? "bg-white text-primary-800 shadow-sm" : "text-neutral-500 hover:text-neutral-800"}`}>{label}</button>
                ))}
              </div>
              <select value={sortBy} onChange={(e) => setSortBy(e.target.value)} className="min-h-[44px] w-full sm:w-auto border border-neutral-300 rounded-xl px-3 bg-white text-sm font-semibold text-neutral-700">
                <option value="queue">Queue order</option>
                <option value="recent">Newest first</option>
                <option value="name">Citizen name</option>
              </select>
            </div>
          </div>
          <div className="mt-3 flex flex-col sm:flex-row sm:items-center sm:justify-between gap-1.5 text-xs text-neutral-500">
            <div className="inline-flex items-center gap-1"><ListFilter className="h-4 w-4" /> {combined.length} matching token{combined.length === 1 ? "" : "s"}</div>
            <div className="inline-flex items-center gap-1"><Clock3 className="h-4 w-4" /> Live refresh every {POLL_MS / 1000}s</div>
          </div>
        </Card>

        <div className="mt-5">
          {loading ? <Card className="p-8 text-center text-neutral-500">{t("staff.queue.loading", "Loading queue...")}</Card> : visible.length === 0 ? <EmptyState label={query || statusFilter !== "ALL" ? t("staff.queue.noMatches", "No tokens match these filters.") : t("staff.queue.empty", "No active tokens.")} /> : (
            <div className="space-y-2">{visible.map(renderToken)}</div>
          )}
        </div>

        {!loading && pageCount > 1 && (
          <div className="mt-5 flex flex-col sm:flex-row sm:items-center sm:justify-between gap-3 rounded-xl border border-neutral-200 bg-white p-3">
            <p className="text-sm text-neutral-500">{t("staff.queue.page", "Page")} {page} / {pageCount}</p>
            <div className="grid grid-cols-2 sm:flex gap-2 w-full sm:w-auto">
              <button type="button" disabled={page <= 1} onClick={() => setPage((p) => Math.max(1, p - 1))} className="inline-flex items-center justify-center gap-1 px-3 py-2 rounded-lg border border-neutral-300 disabled:opacity-40"><ChevronLeft className="h-4 w-4" /> Previous</button>
              <button type="button" disabled={page >= pageCount} onClick={() => setPage((p) => Math.min(pageCount, p + 1))} className="inline-flex items-center justify-center gap-1 px-3 py-2 rounded-lg border border-neutral-300 disabled:opacity-40">Next <ChevronRight className="h-4 w-4" /></button>
            </div>
          </div>
        )}
      </div>
    </MainLayout>
  );
};

export default QueueBoard;
