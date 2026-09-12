import { useState, useEffect, useCallback } from "react";
import { Link } from "react-router-dom";
import { useTranslation } from "react-i18next";
import {
  Users,
  Clock,
  PhoneCall,
  ChevronRight,
  AlertCircle,
  ScanLine,
  Activity,
  LayoutList,
} from "lucide-react";
import MainLayout from "../layouts/MainLayout";
import Card from "../components/ui/Card";
import { Skeleton } from "../components/ui/Skeleton";
import { useAuth } from "../auth/AuthContext";
import { fetchQueueSummary, searchStaffTokens } from "../services/staff";

const POLL_MS = 8000;


function waitMinutes(since) {
  if (!since) return null;
  return Math.max(0, Math.round((Date.now() - new Date(since).getTime()) / 60000));
}

function CountBadge({ value, label, tone }) {
  const toneStyles = {
    neutral: "bg-neutral-100 text-neutral-600",
    primary: "bg-primary-100 text-primary-800",
    amber: "bg-amber-100 text-amber-800",
  };
  return (
    <span
      className={`inline-flex items-center gap-1 px-2 py-0.5 rounded-full text-xs font-semibold ${toneStyles[value > 0 ? tone : "neutral"]}`}
    >
      {value} {label}
    </span>
  );
}

function StageCard({ stage, isNe, t }) {
  const { counts, oldestWaitingSince } = stage;
  const hasWaiting = counts.waiting > 0;
  const wait = waitMinutes(oldestWaitingSince);

  return (
    <Link
      to={`/staff/queues/${stage.id}`}
      className={`block p-4 rounded-xl border transition group ${
        hasWaiting
          ? "bg-amber-50/60 border-amber-200 hover:border-amber-300"
          : "bg-white border-neutral-200 hover:border-primary-300 hover:shadow-sm"
      }`}
    >
      <div className="flex items-center justify-between gap-3">
        <div className="min-w-0">
          <p className="font-heading font-semibold text-neutral-900 truncate">
            {isNe ? stage.nameNe : stage.nameEn}
          </p>
          <div className="mt-1.5 flex flex-wrap items-center gap-1.5">
            <CountBadge value={counts.serving} label={t("staff.dashboard.serving", "serving")} tone="primary" />
            <CountBadge value={counts.called} label={t("staff.dashboard.called", "called")} tone="primary" />
            <CountBadge value={counts.waiting} label={t("staff.dashboard.waiting", "waiting")} tone="amber" />
          </div>
          {hasWaiting && wait !== null && (
            <p className="mt-1.5 text-xs text-amber-700 flex items-center gap-1">
              <Clock className="h-3.5 w-3.5" />
              {t("staff.dashboard.longestWait", "Longest wait")}: {wait} {t("staff.dashboard.min", "min")}
            </p>
          )}
        </div>
        <ChevronRight className="h-5 w-5 text-neutral-300 group-hover:text-primary-700 group-hover:translate-x-0.5 transition flex-shrink-0" />
      </div>
    </Link>
  );
}

function FilterToggle({ filter, setFilter, activeCount, totalCount, t }) {
  const options = [
    {
      key: "active",
      label: t("staff.dashboard.filterActive", "Active"),
      count: activeCount,
      icon: Activity,
    },
    {
      key: "all",
      label: t("staff.dashboard.filterAll", "All"),
      count: totalCount,
      icon: LayoutList,
    },
  ];
  return (
    <div
      role="tablist"
      aria-label={t("staff.dashboard.filterLabel", "Filter queue boards")}
      className="inline-flex w-full sm:w-auto rounded-xl bg-neutral-100 p-1 gap-1"
    >
      {options.map((opt) => {
        const Icon = opt.icon;
        const isSelected = filter === opt.key;
        return (
          <button
            key={opt.key}
            type="button"
            role="tab"
            aria-selected={isSelected}
            onClick={() => setFilter(opt.key)}
            className={`flex-1 sm:flex-none inline-flex items-center justify-center gap-1.5 px-3.5 py-1.5 text-sm font-semibold rounded-lg transition-all duration-150 ${
              isSelected
                ? "bg-white text-primary-800 shadow-sm"
                : "text-neutral-500 hover:text-neutral-800"
            }`}
          >
            <Icon className="h-4 w-4" />
            {opt.label}
            <span
              className={`inline-flex items-center justify-center min-w-[1.25rem] h-5 px-1 rounded-full text-xs font-bold ${
                isSelected ? "bg-primary-100 text-primary-800" : "bg-neutral-200 text-neutral-600"
              }`}
            >
              {opt.count}
            </span>
          </button>
        );
      })}
    </div>
  );
}

const hasActivity = (counts) => counts.serving > 0 || counts.checkedIn > 0 || counts.called > 0 || counts.waiting > 0;

const StaffDashboard = () => {
  const { t, i18n } = useTranslation();
  const { user } = useAuth();
  const isNe = i18n.language === "ne";

  const [services, setServices] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState("");
  const [filter, setFilter] = useState("active");
  const [query, setQuery] = useState("");
  const [searchResults, setSearchResults] = useState([]);
  const [searching, setSearching] = useState(false);

  const load = useCallback(async () => {
    try {
      const data = await fetchQueueSummary();
      setServices(data.services || []);
      setError("");
    } catch (err) {
      setError(err.response?.data?.message || t("staff.dashboard.summaryFailed", "Could not load the queue overview."));
    } finally {
      setLoading(false);
    }

  }, []);

  useEffect(() => {
    load();
    const intervalId = setInterval(load, POLL_MS);
    return () => clearInterval(intervalId);
  }, [load]);

  useEffect(() => {
    const q = query.trim();
    if (!q) { setSearchResults([]); setSearching(false); return undefined; }
    const timer = setTimeout(async () => {
      setSearching(true);
      try {
        const data = await searchStaffTokens(q);
        setSearchResults(data.tokens || []);
      } catch {
        setSearchResults([]);
      } finally {
        setSearching(false);
      }
    }, 250);
    return () => clearTimeout(timer);
  }, [query]);

  const totalWaiting = services.reduce(
    (sum, s) => sum + s.stages.reduce((stageSum, st) => stageSum + st.counts.waiting, 0),
    0,
  );
  const totalActive = services.reduce(
    (sum, s) => sum + s.stages.reduce(
      (stageSum, st) => stageSum + st.counts.serving + st.counts.checkedIn + st.counts.called + st.counts.waiting,
      0,
    ),
    0,
  );

  const totalStageCount = services.reduce((sum, s) => sum + s.stages.length, 0);
  const activeStageCount = services.reduce(
    (sum, s) => sum + s.stages.filter((st) => hasActivity(st.counts)).length,
    0,
  );

  const visibleServices =
    filter === "active"
      ? services
          .map((s) => ({ ...s, stages: s.stages.filter((st) => hasActivity(st.counts)) }))
          .filter((s) => s.stages.length > 0)
      : services;

  return (
    <MainLayout>
      <div className="w-full max-w-4xl mx-auto py-3 sm:py-4 px-1 sm:px-2">
        <div>
          <p className="text-xs uppercase tracking-[0.16em] font-semibold text-neutral-500">{user?.office?.nameEn || user?.office?.nameNe || "Government office"}</p>
          <h1 className="mt-1 text-2xl sm:text-3xl font-heading font-bold text-neutral-900 tracking-tight">
            {t("staff.dashboard.welcome", { name: user?.name || "" })}
          </h1>
          <p className="mt-2 text-neutral-600">
            {loading ? t("staff.dashboard.subtitle") : `${totalActive} active tokens across ${totalStageCount} queues`}
          </p>
        </div>

        <div className="grid grid-cols-2 xl:grid-cols-4 gap-2.5 sm:gap-3 mt-5">
          <Card className="p-3 sm:p-4 min-w-0"><div className="text-[11px] sm:text-xs uppercase tracking-wide text-neutral-500 font-semibold">Waiting</div><div className="mt-1 text-2xl font-heading font-bold text-neutral-900">{totalWaiting}</div></Card>
          <Card className="p-3 sm:p-4 min-w-0"><div className="text-[11px] sm:text-xs uppercase tracking-wide text-neutral-500 font-semibold">Called</div><div className="mt-1 text-2xl font-heading font-bold text-amber-700">{services.reduce((sum,s)=>sum+s.stages.reduce((a,st)=>a+st.counts.called,0),0)}</div></Card>
          <Card className="p-3 sm:p-4 min-w-0"><div className="text-[11px] sm:text-xs uppercase tracking-wide text-neutral-500 font-semibold">Serving</div><div className="mt-1 text-2xl font-heading font-bold text-primary-800">{services.reduce((sum,s)=>sum+s.stages.reduce((a,st)=>a+st.counts.serving,0),0)}</div></Card>
          <Card className="p-3 sm:p-4 min-w-0"><div className="text-[11px] sm:text-xs uppercase tracking-wide text-neutral-500 font-semibold">Queues active</div><div className="mt-1 text-2xl font-heading font-bold text-neutral-900">{activeStageCount}</div></Card>
        </div>

        <Card className="mt-5 p-3 sm:p-5 overflow-hidden">
          <div className="flex flex-col sm:flex-row sm:items-center sm:justify-between gap-2 mb-3">
            <div>
              <div className="flex items-center gap-2 text-sm font-semibold text-neutral-900">
                <Users className="h-4 w-4 text-primary-700" />
                {t("staff.dashboard.globalSearch", "Find a token")}
              </div>
              <p className="mt-1 text-xs text-neutral-500">{t("staff.dashboard.searchHelp", "Search your office by token number, citizen name or phone.")}</p>
            </div>
            {query && (
              <button type="button" onClick={() => setQuery("")} className="self-start sm:self-auto text-xs font-semibold text-neutral-500 hover:text-neutral-800">
                {t("staff.dashboard.clearSearch", "Clear")}
              </button>
            )}
          </div>
          <div className="relative">
            <ScanLine className="absolute left-3 top-1/2 -translate-y-1/2 h-5 w-5 text-neutral-400" />
            <input value={query} onChange={e=>setQuery(e.target.value)} placeholder={t("staff.dashboard.searchPlaceholder", "Search token number, citizen name or phone...")} className="w-full min-h-[50px] pl-10 pr-4 text-sm sm:text-base border border-neutral-300 rounded-xl bg-white focus:border-primary-500 focus:ring-4 focus:ring-primary-100 outline-none" aria-label={t("staff.dashboard.globalSearch", "Find a token")} />
          </div>
          {query && (
            <div className="mt-3">
              {searching ? (
                <p className="text-sm text-neutral-500 py-2">Searching…</p>
              ) : searchResults.length ? (
                <>
                  <div className="flex flex-col xs:flex-row xs:items-center xs:justify-between gap-1.5 mb-2 text-xs text-neutral-500">
                    <span>{searchResults.length} result{searchResults.length === 1 ? "" : "s"}</span>
                    <span>Click a token to open its queue</span>
                  </div>
                  <div className="space-y-2">
                    {searchResults.slice(0,8).map(token => (
                      <Link key={token.id} to={token.currentStage?.id ? `/staff/queues/${token.currentStage.id}` : "/staff/dashboard"} className="flex items-start justify-between gap-2 p-3 rounded-xl bg-neutral-50 border border-neutral-200 min-w-0 hover:border-primary-300 hover:bg-primary-50/40 transition">
                        <div className="min-w-0 overflow-hidden">
                          <p className="font-semibold text-neutral-900 truncate">{token.tokenNumber} <span className="font-normal text-neutral-600">— {token.user?.name || "Citizen"}</span></p>
                          <p className="text-xs text-neutral-500 truncate">{token.service?.nameEn} · {token.currentStage?.nameEn}</p>
                        </div>
                        <span className="shrink-0 text-xs font-semibold text-primary-700">{token.status}</span>
                      </Link>
                    ))}
                  </div>
                </>
              ) : (
                <p className="text-sm text-neutral-500 py-2">No active tokens found in your office.</p>
              )}
            </div>
          )}
        </Card>

        <div className="mt-5 sm:mt-6">
          <div className="flex flex-col sm:flex-row sm:items-center sm:justify-between gap-3 mb-3">
            <h2 className="flex items-center gap-2 font-heading font-semibold text-neutral-900">
              <Users className="h-5 w-5 text-neutral-500" />
              {t("staff.dashboard.queueBoards", "Queue Boards")}
            </h2>
            {!loading && totalStageCount > 0 && (
              <FilterToggle
                filter={filter}
                setFilter={setFilter}
                activeCount={activeStageCount}
                totalCount={totalStageCount}
                t={t}
              />
            )}
          </div>

          {error && (
            <div className="p-4 bg-red-50 border border-red-200 rounded-lg text-sm text-red-700 flex items-start gap-2" role="alert">
              <AlertCircle className="h-5 w-5 flex-shrink-0" />
              <span>{error}</span>
            </div>
          )}

          {loading ? (
            <div className="space-y-3">
              <Skeleton className="h-20 w-full rounded-xl" />
              <Skeleton className="h-20 w-full rounded-xl" />
              <Skeleton className="h-20 w-full rounded-xl" />
            </div>
          ) : services.length === 0 ? (
            <Card className="p-6 text-center">
              <PhoneCall className="h-8 w-8 text-neutral-300 mx-auto" />
              <p className="mt-3 text-sm text-neutral-600">{t("staff.dashboard.noQueues", "No stages found.")}</p>
            </Card>
          ) : visibleServices.length === 0 ? (
            <Card className="p-6 text-center">
              <Users className="h-8 w-8 text-neutral-300 mx-auto" />
              <p className="mt-3 text-sm text-neutral-600">
                {t("staff.dashboard.noActiveQueues", "No queues have anyone waiting, called, checked in, or being served right now.")}
              </p>
              <button
                type="button"
                onClick={() => setFilter("all")}
                className="mt-3 text-sm font-semibold text-primary-700 hover:text-primary-800"
              >
                {t("staff.dashboard.showAllQueues", "Show all queues")}
              </button>
            </Card>
          ) : (
            <div className="space-y-4 sm:space-y-5">
              {visibleServices.map((service) => (
                <div key={service.id}>
                  <p className="text-xs font-semibold text-neutral-500 uppercase tracking-wide mb-2">
                    {isNe ? service.nameNe : service.nameEn}
                  </p>
                  <div className="space-y-2">
                    {service.stages.map((stage) => (
                      <StageCard key={stage.id} stage={stage} isNe={isNe} t={t} />
                    ))}
                  </div>
                </div>
              ))}
            </div>
          )}
        </div>
      </div>
    </MainLayout>
  );
};

export default StaffDashboard;
