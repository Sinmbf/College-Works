import { useState, useMemo } from "react";
import {
  Play,
  CheckCircle2,
  Clock,
  AlertTriangle,
  RotateCcw,
  UserPlus,
  SkipForward,
  Star,
  Plus,
  Users,
  Activity,
  Smartphone,
  ArrowDown,
  ArrowUp,
  Timer,
  ListChecks,
} from "lucide-react";

/* =========================================================================
   CONSTANTS
   ========================================================================= */

const INITIAL_TOKEN_IDS = [
  "A001",
  "A002",
  "A003",
  "A004",
  "A005",
  "A006",
  "A007",
];
const BASE_SIM_MINUTES = 10 * 60; // simulation clock starts at 10:00 AM
const INITIAL_AVG_DURATION = 10; // minutes
const HISTORY_LIMIT = 5; // rolling window of completed services
const DELAY_INCREMENT = 5; // minutes added per "Add Service Delay" click
const MAX_COUNTERS = 6;

/* =========================================================================
   PURE HELPERS
   ========================================================================= */

function formatSimTime(offsetMinutes) {
  const total = BASE_SIM_MINUTES + offsetMinutes;
  let hours = Math.floor(total / 60) % 24;
  const minutes = ((total % 60) + 60) % 60;
  const period = hours >= 12 ? "PM" : "AM";
  hours = hours % 12;
  if (hours === 0) hours = 12;
  return `${hours}:${String(minutes).padStart(2, "0")} ${period}`;
}

function makeToken(id, order, overrides = {}) {
  return {
    id,
    order,
    status: "waiting", // waiting | serving | completed | skipped
    priority: false,
    counterId: null,
    serviceStartMin: null,
    expectedDuration: null,
    actualDuration: null,
    ...overrides,
  };
}

function makeCounter(id, overrides = {}) {
  return { id, available: true, currentTokenId: null, ...overrides };
}

// Priority citizens are served ahead of the regular queue, in the order they
// arrived among themselves. They never interrupt a service already underway.
function getOrderedWaiting(tokens) {
  const waiting = tokens.filter((t) => t.status === "waiting");
  const priority = waiting
    .filter((t) => t.priority)
    .sort((a, b) => a.order - b.order);
  const normal = waiting
    .filter((t) => !t.priority)
    .sort((a, b) => a.order - b.order);
  return [...priority, ...normal];
}

// The heart of the simulator: figure out when each active counter will next
// be free, then assign each waiting citizen (in queue order) to whichever
// counter frees up earliest. This is recomputed from scratch every time the
// queue state changes, so the estimate always reflects current conditions.
function computeQueueEstimates(tokens, counters, simMinutes, avgDuration) {
  const freeAt = [];

  counters.forEach((counter) => {
    if (!counter.available) return; // unavailable counters contribute no capacity
    if (counter.currentTokenId) {
      const current = tokens.find((t) => t.id === counter.currentTokenId);
      if (current) {
        const elapsed = simMinutes - current.serviceStartMin;
        const expected = current.expectedDuration ?? avgDuration;
        // Never let an overrunning service freeze the estimate at 0 forever;
        // floor it at 1 minute so it keeps reflecting "in progress".
        const remaining = Math.max(expected - elapsed, 1);
        freeAt.push(simMinutes + remaining);
        return;
      }
    }
    freeAt.push(simMinutes); // idle & available -> free right now
  });

  const ordered = getOrderedWaiting(tokens);
  const servingCount = tokens.filter((t) => t.status === "serving").length;
  const slots = [...freeAt].sort((a, b) => a - b);

  const estimates = {};

  ordered.forEach((token, idx) => {
    let startsAt = null;
    if (slots.length > 0) {
      let minIdx = 0;
      for (let i = 1; i < slots.length; i++) {
        if (slots[i] < slots[minIdx]) minIdx = i;
      }
      startsAt = slots[minIdx];
      slots[minIdx] = startsAt + avgDuration; // that counter is busy again until then
    }
    estimates[token.id] = {
      position: servingCount + idx + 1,
      wait:
        startsAt === null
          ? null
          : Math.max(Math.round(startsAt - simMinutes), 0),
      startsAt,
    };
  });

  tokens.forEach((t) => {
    if (t.status === "serving") {
      estimates[t.id] = { position: 1, wait: 0, startsAt: simMinutes };
    }
  });

  return estimates;
}

function getDelta(tokenId, estimates, prevEstimates) {
  const cur = estimates[tokenId];
  const prev = prevEstimates[tokenId];
  if (!cur || !prev || cur.wait == null || prev.wait == null) return null;
  if (cur.wait === prev.wait) return null;
  return {
    from: prev.wait,
    to: cur.wait,
    direction: cur.wait > prev.wait ? "up" : "down",
  };
}

function serviceTimeCell(token, simMinutes) {
  if (token.status === "serving") {
    const elapsed = simMinutes - token.serviceStartMin;
    return `${elapsed} / ${token.expectedDuration} min`;
  }
  if (token.status === "completed") return `${token.actualDuration} min`;
  return "—";
}

function waitCell(token, est) {
  if (token.status === "completed") return "Done";
  if (token.status === "skipped") return "Skipped";
  if (token.status === "serving") return "In service";
  if (!est || est.wait == null) return "—";
  return `${est.wait} min`;
}

/* =========================================================================
   STATE + ACTIONS  (each action is a pure function: (state, ...) => state)
   ========================================================================= */

function withLog(state, message, tag = "info") {
  return {
    ...state,
    log: [
      {
        id: state.logIdCounter,
        time: formatSimTime(state.simMinutes),
        message,
        tag,
      },
      ...state.log,
    ],
    logIdCounter: state.logIdCounter + 1,
  };
}

function buildInitialState() {
  const counters = [makeCounter(1), makeCounter(2), makeCounter(3)];
  const tokens = INITIAL_TOKEN_IDS.map((id, i) => makeToken(id, i));
  return {
    counters,
    tokens,
    simMinutes: 0,
    avgDuration: INITIAL_AVG_DURATION,
    history: [],
    log: [
      {
        id: 0,
        time: formatSimTime(0),
        message: "Simulation initialized",
        tag: "system",
      },
    ],
    logIdCounter: 1,
    nextOrder: tokens.length,
    nextTokenNum: 8,
    focusedCounterId: 1,
    selectedTokenId: "A001",
  };
}

function advanceClock(state, minutes) {
  const newTime = state.simMinutes + minutes;
  return withLog(
    { ...state, simMinutes: newTime },
    `Simulation time advanced ${minutes} min (now ${formatSimTime(newTime)})`,
    "clock",
  );
}

function startService(state, counterId) {
  const counter = state.counters.find((c) => c.id === counterId);
  if (!counter || !counter.available || counter.currentTokenId) return state;

  const next = getOrderedWaiting(state.tokens)[0];
  if (!next)
    return withLog(
      state,
      `No citizens waiting to start on Counter ${counterId}`,
      "warn",
    );

  const tokens = state.tokens.map((t) =>
    t.id === next.id
      ? {
          ...t,
          status: "serving",
          counterId,
          serviceStartMin: state.simMinutes,
          expectedDuration: state.avgDuration,
        }
      : t,
  );
  const counters = state.counters.map((c) =>
    c.id === counterId ? { ...c, currentTokenId: next.id } : c,
  );

  return withLog(
    { ...state, tokens, counters },
    `${next.id} started service on Counter ${counterId}`,
    "start",
  );
}

function completeService(state, counterId) {
  const counter = state.counters.find((c) => c.id === counterId);
  if (!counter || !counter.currentTokenId) {
    return withLog(
      state,
      `Counter ${counterId} has no active service to complete`,
      "warn",
    );
  }

  const tokenId = counter.currentTokenId;
  const token = state.tokens.find((t) => t.id === tokenId);
  const actualDuration = Math.max(state.simMinutes - token.serviceStartMin, 1);

  let history = [...state.history, actualDuration];
  if (history.length > HISTORY_LIMIT)
    history = history.slice(history.length - HISTORY_LIMIT);
  const avgDuration = Math.round(
    history.reduce((a, b) => a + b, 0) / history.length,
  );

  let tokens = state.tokens.map((t) =>
    t.id === tokenId ? { ...t, status: "completed", actualDuration } : t,
  );
  let counters = state.counters.map((c) =>
    c.id === counterId ? { ...c, currentTokenId: null } : c,
  );

  let next = withLog(
    { ...state, tokens, counters, history, avgDuration },
    `${tokenId} completed on Counter ${counterId} (${actualDuration} min actual, avg now ${avgDuration} min)`,
    "complete",
  );

  // If this counter is still available, immediately pull in the next
  // eligible citizen -- a completed service frees the counter for reuse.
  const stillAvailable = counters.find((c) => c.id === counterId)?.available;
  if (stillAvailable) {
    const nextToken = getOrderedWaiting(tokens)[0];
    if (nextToken) {
      tokens = tokens.map((t) =>
        t.id === nextToken.id
          ? {
              ...t,
              status: "serving",
              counterId,
              serviceStartMin: state.simMinutes,
              expectedDuration: avgDuration,
            }
          : t,
      );
      counters = counters.map((c) =>
        c.id === counterId ? { ...c, currentTokenId: nextToken.id } : c,
      );
      next = withLog(
        { ...next, tokens, counters },
        `${nextToken.id} started service on Counter ${counterId}`,
        "start",
      );
    }
  }

  return next;
}

function addServiceDelay(state, counterId) {
  const counter = state.counters.find((c) => c.id === counterId);
  if (!counter || !counter.currentTokenId) {
    return withLog(
      state,
      `Counter ${counterId} has no active service to delay`,
      "warn",
    );
  }
  const tokenId = counter.currentTokenId;
  const tokens = state.tokens.map((t) =>
    t.id === tokenId
      ? {
          ...t,
          expectedDuration:
            (t.expectedDuration ?? state.avgDuration) + DELAY_INCREMENT,
        }
      : t,
  );
  return withLog(
    { ...state, tokens },
    `${tokenId} service delayed +${DELAY_INCREMENT} min on Counter ${counterId}`,
    "delay",
  );
}

function addCitizen(state, priority = false) {
  const id = `A${String(state.nextTokenNum).padStart(3, "0")}`;
  const token = makeToken(id, state.nextOrder, { priority });
  const tokens = [...state.tokens, token];
  const message = priority
    ? `${id} added as PRIORITY citizen — moved ahead of the regular queue`
    : `${id} added to waiting queue`;
  return withLog(
    {
      ...state,
      tokens,
      nextOrder: state.nextOrder + 1,
      nextTokenNum: state.nextTokenNum + 1,
    },
    message,
    priority ? "priority" : "info",
  );
}

function skipToken(state, explicitTokenId) {
  const ordered = getOrderedWaiting(state.tokens);
  const target = explicitTokenId
    ? state.tokens.find(
        (t) => t.id === explicitTokenId && t.status === "waiting",
      )
    : ordered[0];
  if (!target)
    return withLog(state, "No eligible waiting citizen to skip", "warn");

  const tokens = state.tokens.map((t) =>
    t.id === target.id ? { ...t, status: "skipped" } : t,
  );
  return withLog({ ...state, tokens }, `${target.id} skipped`, "skip");
}

function addCounter(state) {
  if (state.counters.length >= MAX_COUNTERS) return state;
  const id = state.counters.length
    ? Math.max(...state.counters.map((c) => c.id)) + 1
    : 1;
  const counters = [...state.counters, makeCounter(id)];
  return withLog({ ...state, counters }, `Counter ${id} added`, "info");
}

function removeCounter(state, counterId) {
  if (state.counters.length <= 1)
    return withLog(state, "At least one counter is required", "warn");
  const counter = state.counters.find((c) => c.id === counterId);
  if (counter?.currentTokenId) {
    return withLog(
      state,
      `Cannot remove Counter ${counterId} while it is serving ${counter.currentTokenId}`,
      "warn",
    );
  }
  const counters = state.counters.filter((c) => c.id !== counterId);
  const focusedCounterId =
    state.focusedCounterId === counterId
      ? (counters[0]?.id ?? null)
      : state.focusedCounterId;
  return withLog(
    { ...state, counters, focusedCounterId },
    `Counter ${counterId} removed`,
    "info",
  );
}

function setCounterAvailability(state, counterId, available) {
  const counters = state.counters.map((c) =>
    c.id === counterId ? { ...c, available } : c,
  );
  return withLog(
    { ...state, counters },
    `Counter ${counterId} marked ${available ? "available" : "unavailable"} — waiting times recalculated`,
    available ? "available" : "unavailable",
  );
}

/* =========================================================================
   DEMO SCENARIOS
   ========================================================================= */

function singleCounterSetup() {
  let s = buildInitialState();
  return {
    ...s,
    counters: [
      makeCounter(1),
      makeCounter(2, { available: false }),
      makeCounter(3, { available: false }),
    ],
  };
}

function scenarioNormalQueue() {
  let s = singleCounterSetup();
  s = withLog(s, "Scenario loaded: Normal Queue", "scenario");
  s = startService(s, 1);
  return { ...s, focusedCounterId: 1, selectedTokenId: "A005" };
}

function scenarioServiceDelay() {
  let s = singleCounterSetup();
  s = withLog(s, "Scenario loaded: Service Takes Longer", "scenario");
  s = startService(s, 1);
  return { ...s, focusedCounterId: 1, selectedTokenId: "A004" };
}

function scenarioEarlyFinish() {
  let s = singleCounterSetup();
  s = withLog(s, "Scenario loaded: Service Finishes Early", "scenario");
  s = startService(s, 1);
  s = advanceClock(s, 6);
  return { ...s, focusedCounterId: 1, selectedTokenId: "A002" };
}

function scenarioCounterUnavailable() {
  let s = buildInitialState();
  s = withLog(s, "Scenario loaded: Counter Becomes Unavailable", "scenario");
  s = startService(s, 1);
  s = startService(s, 2);
  s = startService(s, 3);
  return { ...s, focusedCounterId: 2, selectedTokenId: "A007" };
}

function scenarioSkip() {
  let s = singleCounterSetup();
  s = withLog(s, "Scenario loaded: Citizen Gets Skipped", "scenario");
  s = startService(s, 1);
  return { ...s, focusedCounterId: 1, selectedTokenId: "A004" };
}

function scenarioPriority() {
  let s = singleCounterSetup();
  s = withLog(s, "Scenario loaded: Priority Citizen", "scenario");
  s = startService(s, 1);
  return { ...s, focusedCounterId: 1, selectedTokenId: "A005" };
}

/* =========================================================================
   SMALL PRESENTATIONAL PIECES
   ========================================================================= */

function ActionButton({
  onClick,
  disabled,
  icon: Icon,
  tone = "primary",
  children,
}) {
  const tones = {
    primary: "bg-blue-600 text-white hover:bg-blue-700",
    success: "bg-emerald-600 text-white hover:bg-emerald-700",
    warning: "bg-orange-500 text-white hover:bg-orange-600",
    danger: "bg-red-600 text-white hover:bg-red-700",
    amber: "bg-amber-500 text-white hover:bg-amber-600",
    outline: "border border-slate-300 text-slate-700 hover:bg-slate-50",
  };
  return (
    <button
      onClick={onClick}
      disabled={disabled}
      className={`w-full inline-flex items-center justify-center gap-2 rounded-lg px-3 py-2 text-sm font-medium transition-colors focus:outline-none focus:ring-2 focus:ring-offset-1 focus:ring-blue-500 disabled:opacity-40 disabled:cursor-not-allowed disabled:hover:bg-none ${tones[tone]}`}
    >
      {Icon && <Icon className="w-4 h-4 shrink-0" />}
      <span>{children}</span>
    </button>
  );
}

function ScenarioButton({ onClick, children }) {
  return (
    <button
      onClick={onClick}
      className="text-left text-xs font-medium px-3 py-2 rounded-lg border border-violet-200 bg-violet-50 text-violet-700 hover:bg-violet-100 transition-colors focus:outline-none focus:ring-2 focus:ring-violet-400"
    >
      {children}
    </button>
  );
}

function StatusBadge({ token }) {
  const config = {
    serving: {
      label: "Serving",
      cls: "bg-emerald-100 text-emerald-700 border-emerald-200",
    },
    completed: {
      label: "Completed",
      cls: "bg-blue-100 text-blue-700 border-blue-200",
    },
    skipped: {
      label: "Skipped",
      cls: "bg-red-100 text-red-700 border-red-200",
    },
    waiting: token.priority
      ? {
          label: "Priority",
          cls: "bg-amber-100 text-amber-700 border-amber-200",
        }
      : {
          label: "Waiting",
          cls: "bg-slate-100 text-slate-600 border-slate-200",
        },
  };
  const { label, cls } = config[token.status] || config.waiting;
  return (
    <span
      className={`inline-flex items-center gap-1 rounded-full border px-2 py-0.5 text-xs font-medium ${cls}`}
    >
      {token.status === "serving" && (
        <span className="w-1.5 h-1.5 rounded-full bg-emerald-500 animate-pulse" />
      )}
      {token.status === "waiting" && token.priority && (
        <Star className="w-3 h-3" />
      )}
      {label}
    </span>
  );
}

function DeltaTag({ delta }) {
  if (!delta) return null;
  const isDown = delta.direction === "down";
  return (
    <span
      className={`inline-flex items-center gap-0.5 text-xs font-semibold ml-2 ${isDown ? "text-emerald-600" : "text-orange-600"}`}
    >
      {isDown ? (
        <ArrowDown className="w-3 h-3" />
      ) : (
        <ArrowUp className="w-3 h-3" />
      )}
      {delta.from}→{delta.to}
    </span>
  );
}

function StatPill({ label, value, icon: Icon }) {
  return (
    <div className="bg-white border border-slate-200 rounded-lg px-3 py-2.5 flex items-center gap-2.5">
      <div className="w-8 h-8 rounded-md bg-blue-50 flex items-center justify-center shrink-0">
        <Icon className="w-4 h-4 text-blue-600" />
      </div>
      <div className="min-w-0">
        <div className="text-xs text-slate-400 truncate">{label}</div>
        <div className="text-sm font-bold text-slate-800 font-mono">
          {value}
        </div>
      </div>
    </div>
  );
}

function CounterCard({
  counter,
  token,
  simMinutes,
  focused,
  onFocus,
  onToggleAvailable,
  onRemove,
  canRemove,
}) {
  const isServing = Boolean(counter.currentTokenId) && Boolean(token);
  let elapsed = 0;
  let expected = 0;
  let overdue = false;
  let progressPct = 0;
  let timeLabel = "";

  if (isServing) {
    elapsed = simMinutes - token.serviceStartMin;
    expected = token.expectedDuration;
    overdue = elapsed >= expected;
    progressPct = Math.min((elapsed / expected) * 100, 100);
    timeLabel = overdue
      ? `Overdue ${elapsed - expected} min`
      : `${elapsed}/${expected} min`;
  }

  return (
    <div
      role="button"
      tabIndex={0}
      onClick={onFocus}
      onKeyDown={(e) => {
        if (e.key === "Enter" || e.key === " ") {
          e.preventDefault();
          onFocus();
        }
      }}
      className={`w-full text-left rounded-lg border p-3 cursor-pointer transition-colors focus:outline-none focus:ring-2 focus:ring-blue-400 ${
        focused
          ? "border-blue-500 ring-1 ring-blue-500 bg-blue-50"
          : "border-slate-200 bg-white hover:border-slate-300"
      } ${!counter.available ? "opacity-70" : ""}`}
    >
      <div className="flex items-center justify-between mb-1.5">
        <span className="text-sm font-semibold text-slate-800">
          Counter {counter.id}
        </span>
        <span
          className={`text-xs px-1.5 py-0.5 rounded-full font-medium ${
            counter.available
              ? "bg-emerald-100 text-emerald-700"
              : "bg-red-100 text-red-700"
          }`}
        >
          {counter.available ? "Available" : "Unavailable"}
        </span>
      </div>

      {isServing ? (
        <>
          <div className="text-xs text-slate-500 font-mono mb-1">
            {token.id} · {timeLabel}
          </div>
          <div className="h-1.5 w-full bg-slate-100 rounded-full overflow-hidden">
            <div
              className={`h-full rounded-full ${overdue ? "bg-orange-500" : "bg-emerald-500"}`}
              style={{ width: `${progressPct}%` }}
            />
          </div>
        </>
      ) : (
        <div className="text-xs text-slate-400">No active service</div>
      )}

      <div className="flex gap-1.5 mt-2.5" onClick={(e) => e.stopPropagation()}>
        <button
          onClick={onToggleAvailable}
          className="flex-1 text-xs px-2 py-1 rounded border border-slate-200 text-slate-600 hover:bg-slate-50 focus:outline-none focus:ring-2 focus:ring-blue-400"
        >
          {counter.available ? "Mark unavailable" : "Mark available"}
        </button>
        <button
          onClick={onRemove}
          disabled={!canRemove}
          className="text-xs px-2 py-1 rounded border border-slate-200 text-slate-400 hover:bg-red-50 hover:text-red-600 disabled:opacity-30 disabled:hover:bg-transparent disabled:hover:text-slate-400 focus:outline-none focus:ring-2 focus:ring-blue-400"
        >
          Remove
        </button>
      </div>
    </div>
  );
}

function tagClass(tag) {
  const map = {
    system: "text-slate-500",
    scenario: "text-violet-600 font-semibold",
    start: "text-blue-600",
    complete: "text-emerald-600",
    delay: "text-orange-600",
    skip: "text-red-600",
    priority: "text-amber-600 font-semibold",
    available: "text-emerald-600",
    unavailable: "text-red-600",
    warn: "text-red-500",
    clock: "text-slate-400",
    info: "text-slate-600",
  };
  return map[tag] || "text-slate-600";
}

/* =========================================================================
   MAIN COMPONENT
   ========================================================================= */

export default function QueueSimulator() {
  const [state, setState] = useState(buildInitialState);
  const [prevEstimates, setPrevEstimates] = useState({});

  const {
    tokens,
    counters,
    simMinutes,
    avgDuration,
    log,
    focusedCounterId,
    selectedTokenId,
  } = state;

  const estimates = useMemo(
    () => computeQueueEstimates(tokens, counters, simMinutes, avgDuration),
    [tokens, counters, simMinutes, avgDuration],
  );
  const orderedWaiting = useMemo(() => getOrderedWaiting(tokens), [tokens]);
  const sortedTokens = useMemo(
    () => [...tokens].sort((a, b) => a.order - b.order),
    [tokens],
  );

  const runAction = (fn) => {
    setPrevEstimates(estimates);
    setState((prev) => fn(prev));
  };
  const runReset = (fn) => {
    setPrevEstimates({});
    setState(() => fn());
  };

  const setFocusedCounterId = (id) =>
    setState((prev) => ({ ...prev, focusedCounterId: id }));
  const setSelectedTokenId = (id) =>
    setState((prev) => ({ ...prev, selectedTokenId: id }));

  const focusedCounter =
    counters.find((c) => c.id === focusedCounterId) || counters[0] || null;
  const selectedToken =
    tokens.find((t) => t.id === selectedTokenId) || sortedTokens[0] || null;
  const est = selectedToken ? estimates[selectedToken.id] : null;
  const delta =
    selectedToken && selectedToken.status === "waiting"
      ? getDelta(selectedToken.id, estimates, prevEstimates)
      : null;
  const skipTarget =
    selectedToken?.status === "waiting"
      ? selectedToken
      : orderedWaiting[0] || null;

  const canStart = Boolean(
    focusedCounter &&
    focusedCounter.available &&
    !focusedCounter.currentTokenId &&
    orderedWaiting.length > 0,
  );
  const canComplete = Boolean(focusedCounter && focusedCounter.currentTokenId);
  const allCountersUnavailable =
    counters.length > 0 && counters.every((c) => !c.available);
  const waitingCount = tokens.filter((t) => t.status === "waiting").length;
  const completedCount = tokens.filter((t) => t.status === "completed").length;
  const lastEventMessage = log[0]?.message || "";

  let serviceHint = "";
  if (!focusedCounter) serviceHint = "No counter selected.";
  else if (!focusedCounter.available)
    serviceHint = `Counter ${focusedCounter.id} is unavailable.`;
  else if (focusedCounter.currentTokenId)
    serviceHint = `Counter ${focusedCounter.id} is serving ${focusedCounter.currentTokenId}.`;
  else if (orderedWaiting.length === 0) serviceHint = "No citizens waiting.";
  else serviceHint = `Counter ${focusedCounter.id} is idle and ready.`;

  return (
    <div className="min-h-screen bg-slate-50">
      <div className="max-w-7xl mx-auto p-4 md:p-6">
        {/* ---------------- HEADER ---------------- */}
        <header className="mb-2">
          <div className="flex flex-col md:flex-row md:items-end md:justify-between gap-4">
            <div>
              <p className="text-xs font-semibold uppercase tracking-wider text-blue-600 mb-1">
                Smart Queue Management System · Prototype
              </p>
              <h1 className="text-2xl md:text-3xl font-bold text-slate-900">
                Dynamic Estimated Waiting Time
              </h1>
              <p className="text-sm text-slate-500 mt-1 max-w-xl">
                Waiting time is recalculated whenever the queue changes — not
                just once when a token is issued.
              </p>
            </div>

            <div className="bg-white border border-slate-200 rounded-xl shadow-sm px-4 py-3 flex items-center gap-4 shrink-0">
              <div>
                <div className="text-xs text-slate-400 flex items-center gap-1">
                  <Clock className="w-3 h-3" /> Simulation Time
                </div>
                <div className="text-xl font-mono font-bold text-slate-800">
                  {formatSimTime(simMinutes)}
                </div>
              </div>
              <div className="flex gap-1.5">
                <button
                  onClick={() => runAction((s) => advanceClock(s, 1))}
                  className="text-xs font-medium px-2.5 py-1.5 rounded-md border border-slate-200 hover:bg-slate-50 text-slate-600 focus:outline-none focus:ring-2 focus:ring-blue-400"
                >
                  +1m
                </button>
                <button
                  onClick={() => runAction((s) => advanceClock(s, 5))}
                  className="text-xs font-medium px-2.5 py-1.5 rounded-md border border-slate-200 hover:bg-slate-50 text-slate-600 focus:outline-none focus:ring-2 focus:ring-blue-400"
                >
                  +5m
                </button>
                <button
                  onClick={() => runAction((s) => advanceClock(s, 10))}
                  className="text-xs font-medium px-2.5 py-1.5 rounded-md border border-slate-200 hover:bg-slate-50 text-slate-600 focus:outline-none focus:ring-2 focus:ring-blue-400"
                >
                  +10m
                </button>
              </div>
            </div>
          </div>

          <div className="grid grid-cols-2 md:grid-cols-4 gap-3 mt-4">
            <StatPill
              label="Avg. Service Duration"
              value={`${avgDuration} min`}
              icon={Timer}
            />
            <StatPill
              label="Active Counters"
              value={`${counters.filter((c) => c.available).length}/${counters.length}`}
              icon={Users}
            />
            <StatPill label="Waiting" value={waitingCount} icon={ListChecks} />
            <StatPill
              label="Completed"
              value={completedCount}
              icon={CheckCircle2}
            />
          </div>
        </header>

        {/* ---------------- MAIN GRID ---------------- */}
        <div className="grid grid-cols-1 lg:grid-cols-12 gap-6 mt-6">
          {/* ---------------- SIDEBAR: SIMULATION CONTROLS ---------------- */}
          <aside className="lg:col-span-4 space-y-5 lg:sticky lg:top-6 self-start">
            {/* Counters */}
            <div className="bg-white border border-slate-200 rounded-xl shadow-sm p-4">
              <div className="flex items-center justify-between mb-3">
                <div className="flex items-center gap-2">
                  <Users className="w-4 h-4 text-slate-400" />
                  <h2 className="text-sm font-semibold text-slate-800">
                    Counters
                  </h2>
                </div>
                <span className="text-xs text-slate-400">
                  Service acts on #{focusedCounterId}
                </span>
              </div>
              <div className="space-y-2 mb-3">
                {counters.map((c) => (
                  <CounterCard
                    key={c.id}
                    counter={c}
                    token={tokens.find((t) => t.id === c.currentTokenId)}
                    simMinutes={simMinutes}
                    focused={c.id === focusedCounterId}
                    onFocus={() => setFocusedCounterId(c.id)}
                    onToggleAvailable={() =>
                      runAction((s) =>
                        setCounterAvailability(s, c.id, !c.available),
                      )
                    }
                    onRemove={() => runAction((s) => removeCounter(s, c.id))}
                    canRemove={counters.length > 1 && !c.currentTokenId}
                  />
                ))}
              </div>
              <ActionButton
                icon={Plus}
                tone="outline"
                disabled={counters.length >= MAX_COUNTERS}
                onClick={() => runAction(addCounter)}
              >
                Add Counter
              </ActionButton>
            </div>

            {/* Service Controls */}
            <div className="bg-white border border-slate-200 rounded-xl shadow-sm p-4">
              <h2 className="text-sm font-semibold text-slate-800 mb-3">
                Service Controls
              </h2>
              <div className="space-y-2">
                <ActionButton
                  icon={Play}
                  tone="primary"
                  disabled={!canStart}
                  onClick={() =>
                    runAction((s) => startService(s, focusedCounterId))
                  }
                >
                  Start Service
                </ActionButton>
                <ActionButton
                  icon={CheckCircle2}
                  tone="success"
                  disabled={!canComplete}
                  onClick={() =>
                    runAction((s) => completeService(s, focusedCounterId))
                  }
                >
                  Complete Service
                </ActionButton>
                <ActionButton
                  icon={Timer}
                  tone="warning"
                  disabled={!canComplete}
                  onClick={() =>
                    runAction((s) => addServiceDelay(s, focusedCounterId))
                  }
                >
                  Add Service Delay +{DELAY_INCREMENT} min
                </ActionButton>
              </div>
              <p className="text-xs text-slate-400 mt-2">{serviceHint}</p>
            </div>

            {/* Queue Controls */}
            <div className="bg-white border border-slate-200 rounded-xl shadow-sm p-4">
              <h2 className="text-sm font-semibold text-slate-800 mb-3">
                Queue Controls
              </h2>
              <div className="space-y-2">
                <ActionButton
                  icon={UserPlus}
                  tone="outline"
                  onClick={() => runAction((s) => addCitizen(s, false))}
                >
                  Add Citizen
                </ActionButton>
                <ActionButton
                  icon={Star}
                  tone="amber"
                  onClick={() => runAction((s) => addCitizen(s, true))}
                >
                  Add Priority Citizen
                </ActionButton>
                <ActionButton
                  icon={SkipForward}
                  tone="danger"
                  disabled={!skipTarget}
                  onClick={() =>
                    runAction((s) =>
                      skipToken(
                        s,
                        selectedToken?.status === "waiting"
                          ? selectedToken.id
                          : null,
                      ),
                    )
                  }
                >
                  {skipTarget
                    ? `Skip Current Token (${skipTarget.id})`
                    : "Skip Current Token"}
                </ActionButton>
              </div>
              <p className="text-xs text-slate-400 mt-2">
                Priority policy: priority citizens queue ahead of regular
                waiting citizens, in arrival order, but never interrupt a
                service already in progress.
              </p>
            </div>

            {/* Scenarios */}
            <div className="bg-white border border-slate-200 rounded-xl shadow-sm p-4">
              <h2 className="text-sm font-semibold text-slate-800 mb-1">
                Demo Scenarios
              </h2>
              <p className="text-xs text-slate-400 mb-3">
                Loads a preset setup — then use the controls above to play it
                out.
              </p>
              <div className="grid grid-cols-1 gap-1.5">
                <ScenarioButton onClick={() => runReset(scenarioNormalQueue)}>
                  1 · Normal Queue
                </ScenarioButton>
                <ScenarioButton onClick={() => runReset(scenarioServiceDelay)}>
                  2 · Service Takes Longer
                </ScenarioButton>
                <ScenarioButton onClick={() => runReset(scenarioEarlyFinish)}>
                  3 · Service Finishes Early
                </ScenarioButton>
                <ScenarioButton
                  onClick={() => runReset(scenarioCounterUnavailable)}
                >
                  4 · Counter Becomes Unavailable
                </ScenarioButton>
                <ScenarioButton onClick={() => runReset(scenarioSkip)}>
                  5 · Citizen Gets Skipped
                </ScenarioButton>
                <ScenarioButton onClick={() => runReset(scenarioPriority)}>
                  6 · Priority Citizen
                </ScenarioButton>
              </div>
            </div>

            <ActionButton
              icon={RotateCcw}
              tone="danger"
              onClick={() => runReset(buildInitialState)}
            >
              Reset Simulation
            </ActionButton>
          </aside>

          {/* ---------------- MAIN CONTENT ---------------- */}
          <main className="lg:col-span-8 space-y-6 min-w-0">
            {/* Current Queue */}
            <div className="bg-white border border-slate-200 rounded-xl shadow-sm p-5">
              <div className="flex items-center justify-between mb-3">
                <div className="flex items-center gap-2">
                  <ListChecks className="w-4 h-4 text-slate-400" />
                  <h2 className="text-sm font-semibold text-slate-800">
                    Current Queue
                  </h2>
                </div>
                <span className="text-xs text-slate-400">
                  {tokens.length} tokens
                </span>
              </div>

              {allCountersUnavailable && (
                <div className="mb-3 flex items-center gap-2 rounded-lg bg-red-50 border border-red-200 px-3 py-2 text-xs text-red-700">
                  <AlertTriangle className="w-3.5 h-3.5 shrink-0" />
                  All counters are unavailable — waiting times cannot be
                  estimated right now.
                </div>
              )}

              <div className="overflow-x-auto">
                <table className="w-full text-sm">
                  <thead>
                    <tr className="text-left text-slate-400 border-b border-slate-200">
                      <th className="py-2 pr-3 font-medium">Token</th>
                      <th className="py-2 pr-3 font-medium">Status</th>
                      <th className="py-2 pr-3 font-medium">Counter</th>
                      <th className="py-2 pr-3 font-medium">Service Time</th>
                      <th className="py-2 pr-3 font-medium">Est. Wait</th>
                    </tr>
                  </thead>
                  <tbody>
                    {sortedTokens.map((t) => {
                      const rowEst = estimates[t.id];
                      const rowDelta =
                        t.status === "waiting"
                          ? getDelta(t.id, estimates, prevEstimates)
                          : null;
                      const isSelected = t.id === selectedTokenId;
                      return (
                        <tr
                          key={t.id}
                          onClick={() => setSelectedTokenId(t.id)}
                          className={`cursor-pointer border-b border-slate-100 last:border-0 transition-colors ${
                            t.status === "serving"
                              ? "bg-emerald-50"
                              : isSelected
                                ? "bg-blue-50"
                                : "hover:bg-slate-50"
                          }`}
                        >
                          <td className="py-2 pr-3 font-mono font-semibold text-slate-800">
                            {t.id}
                          </td>
                          <td className="py-2 pr-3">
                            <StatusBadge token={t} />
                          </td>
                          <td className="py-2 pr-3 text-slate-600">
                            {t.counterId ? `Counter ${t.counterId}` : "—"}
                          </td>
                          <td className="py-2 pr-3 font-mono text-slate-600">
                            {serviceTimeCell(t, simMinutes)}
                          </td>
                          <td className="py-2 pr-3 font-mono text-slate-700">
                            {waitCell(t, rowEst)}
                            <DeltaTag delta={rowDelta} />
                          </td>
                        </tr>
                      );
                    })}
                  </tbody>
                </table>
              </div>
            </div>

            <div className="grid grid-cols-1 xl:grid-cols-2 gap-6">
              {/* Citizen View */}
              <div className="bg-white border border-slate-200 rounded-xl shadow-sm p-5">
                <div className="flex items-center gap-2 mb-4">
                  <Smartphone className="w-4 h-4 text-slate-400" />
                  <h2 className="text-sm font-semibold text-slate-800">
                    Citizen View
                  </h2>
                </div>

                <div className="flex items-center gap-2 mb-4">
                  <label
                    className="text-xs text-slate-500"
                    htmlFor="my-token-select"
                  >
                    My Token
                  </label>
                  <select
                    id="my-token-select"
                    value={selectedToken?.id ?? ""}
                    onChange={(e) => setSelectedTokenId(e.target.value)}
                    className="border border-slate-300 rounded-md px-2 py-1 text-sm font-mono focus:outline-none focus:ring-2 focus:ring-blue-500"
                  >
                    {sortedTokens.map((t) => (
                      <option key={t.id} value={t.id}>
                        {t.id}
                      </option>
                    ))}
                  </select>
                </div>

                {selectedToken && (
                  <div className="rounded-xl border border-slate-200 bg-slate-50 p-5 text-center">
                    <div className="text-xs uppercase tracking-wide text-slate-400 mb-1">
                      My Token
                    </div>
                    <div className="font-mono text-lg font-bold text-slate-800 mb-4">
                      {selectedToken.id}
                    </div>

                    {selectedToken.status === "waiting" && (
                      <>
                        <div className="text-xs uppercase tracking-wide text-slate-400">
                          Queue Position
                        </div>
                        <div className="text-2xl font-bold text-slate-800 mb-3">
                          {est?.position ?? "—"}
                        </div>

                        <div className="text-xs uppercase tracking-wide text-slate-400">
                          Estimated Waiting Time
                        </div>
                        <div className="text-4xl font-bold text-blue-600 font-mono mb-1">
                          {est?.wait != null ? `${est.wait} min` : "—"}
                        </div>
                        {delta && (
                          <div
                            className={`inline-flex items-center gap-1 text-sm font-semibold mb-1 ${
                              delta.direction === "down"
                                ? "text-emerald-600"
                                : "text-orange-600"
                            }`}
                          >
                            {delta.direction === "down" ? (
                              <ArrowDown className="w-3.5 h-3.5" />
                            ) : (
                              <ArrowUp className="w-3.5 h-3.5" />
                            )}
                            was {delta.from} min
                          </div>
                        )}
                      </>
                    )}

                    {selectedToken.status === "serving" && (
                      <div className="py-2">
                        <div className="text-lg font-bold text-emerald-600 mb-1">
                          You're being served now
                        </div>
                        <div className="text-sm text-slate-500">
                          at Counter {selectedToken.counterId}
                        </div>
                      </div>
                    )}

                    {selectedToken.status === "completed" && (
                      <div className="py-2">
                        <div className="text-lg font-bold text-blue-600 mb-1">
                          Service complete
                        </div>
                        <div className="text-sm text-slate-500">
                          Took {selectedToken.actualDuration} minutes
                        </div>
                      </div>
                    )}

                    {selectedToken.status === "skipped" && (
                      <div className="py-2">
                        <div className="text-lg font-bold text-red-600 mb-1">
                          Token skipped
                        </div>
                        <div className="text-sm text-slate-500">
                          Please check with the counter staff
                        </div>
                      </div>
                    )}

                    <div className="flex items-center justify-center gap-2 mt-2">
                      <span className="text-xs uppercase tracking-wide text-slate-400">
                        Status
                      </span>
                      <StatusBadge token={selectedToken} />
                    </div>

                    <div className="text-xs text-slate-400 mt-3">
                      Last updated: {formatSimTime(simMinutes)}
                    </div>

                    {delta && (
                      <div className="mt-3 rounded-lg bg-amber-50 border border-amber-200 px-3 py-2 text-xs text-amber-800 text-left">
                        <span className="font-semibold">
                          Waiting time updated.
                        </span>{" "}
                        {lastEventMessage}
                      </div>
                    )}
                  </div>
                )}

                <p className="text-xs text-slate-400 italic mt-3 text-center">
                  This is an estimate based on current queue conditions and may
                  change.
                </p>
              </div>

              {/* Event Log */}
              <div className="bg-white border border-slate-200 rounded-xl shadow-sm p-5">
                <div className="flex items-center gap-2 mb-3">
                  <Activity className="w-4 h-4 text-slate-400" />
                  <h2 className="text-sm font-semibold text-slate-800">
                    Queue Activity
                  </h2>
                </div>
                <div className="space-y-1.5 max-h-80 overflow-y-auto pr-1">
                  {log.map((entry) => (
                    <div
                      key={entry.id}
                      className="flex gap-2 text-xs leading-relaxed"
                    >
                      <span className="font-mono text-slate-400 shrink-0 w-16">
                        {entry.time}
                      </span>
                      <span className={tagClass(entry.tag)}>
                        {entry.message}
                      </span>
                    </div>
                  ))}
                </div>
              </div>
            </div>
          </main>
        </div>

        <footer className="mt-8 text-center text-xs text-slate-400">
          Prototype for demonstration purposes — estimates are simulated, not
          measured from a live office.
        </footer>
      </div>
    </div>
  );
}
