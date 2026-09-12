import { useTranslation } from "react-i18next";
import { MapPin, FileText, Check, Loader } from "lucide-react";
import RequiredDocumentsList from "./RequiredDocumentsList";


const STATUS_STYLES = {
  completed: {
    circle: "bg-primary-700 text-white border-primary-700",
    label: "text-primary-700",
    line: "bg-primary-700",
  },
  current: {
    circle: "bg-white text-primary-700 border-primary-700 ring-4 ring-primary-100",
    label: "text-primary-700",
    line: "bg-neutral-200",
  },
  upcoming: {
    circle: "bg-white text-neutral-500 border-neutral-300",
    label: "text-neutral-700",
    line: "bg-neutral-200",
  },
  remaining: {
    circle: "bg-white text-neutral-500 border-neutral-300",
    label: "text-neutral-700",
    line: "bg-neutral-200",
  },
};

const StatusIcon = ({ status }) => {
  if (status === "completed") return <Check className="h-4 w-4" aria-hidden="true" />;
  if (status === "current") return <Loader className="h-4 w-4" aria-hidden="true" />;
  return null;
};


const ServiceRoadmap = ({
  stages = [],
  currentStageOrder,
  languageAware = true,
  serviceNameEn,
  serviceNameNe,
}) => {
  const { t, i18n } = useTranslation();
  const isNe = languageAware && i18n.language === "ne";

  const pick = (en, ne) => (isNe ? ne : en);

  if (stages.length === 0) return null;

  return (
    <section
      className="relative w-full min-w-0 overflow-hidden rounded-2xl border border-neutral-200 bg-gradient-to-br from-white via-primary-50/30 to-white p-3 sm:p-6 shadow-sm"
      aria-label={t("services.roadmap.ariaLabel")}
    >

      <header className="mb-4 sm:mb-5 pb-4 border-b border-neutral-200 min-w-0">
        <h2 className="font-heading font-bold text-base sm:text-xl text-neutral-900 break-words [overflow-wrap:anywhere]">
          {pick(serviceNameEn, serviceNameNe) || t("services.roadmap.ariaLabel")}
        </h2>
        <p className="mt-1 text-xs text-neutral-500">
          {t("services.roadmap.stagesCount", { count: stages.length })}
        </p>
      </header>

      <ol className="relative space-y-0 min-w-0">
        {stages.map((stage, idx) => {
          const isLast = idx === stages.length - 1;
          const status =
            typeof currentStageOrder === "number"
              ? stage.stageOrder < currentStageOrder
                ? "completed"
                : stage.stageOrder === currentStageOrder
                ? "current"
                : "upcoming"
              : "remaining";
          const s = STATUS_STYLES[status];

          return (
            <li key={stage.id} className="relative flex gap-2 sm:gap-4 pb-6 last:pb-0 min-w-0">

              <div className="flex flex-col items-center flex-shrink-0">
                <span
                  className={`relative z-10 flex items-center justify-center w-9 h-9 sm:w-10 sm:h-10 rounded-full border-2 text-sm font-bold ${s.circle}`}
                  aria-current={status === "current" ? "step" : undefined}
                >
                  <StatusIcon status={status} />
                  <span className={status === "completed" || status === "current" ? "sr-only" : ""}>
                    {stage.stageOrder}
                  </span>
                </span>
                {!isLast && (
                  <span
                    className={`w-0.5 flex-1 mt-1 rounded-full ${s.line}`}
                    aria-hidden="true"
                  />
                )}
              </div>


              <div className={`flex-1 min-w-0 pt-0.5 overflow-hidden ${status === "current" ? "border-l-2 border-primary-300 pl-2 sm:pl-3 -ml-1 sm:-ml-2 rounded-l" : ""}`}>
                <p className={`text-[11px] font-bold uppercase tracking-wider ${s.label}`}>
                  {t(`services.roadmap.status.${status}`)}
                  <span className="ml-2 text-neutral-400 font-medium normal-case tracking-normal">
                    {t("services.roadmap.stepLabel", { n: stage.stageOrder })}
                  </span>
                </p>
                <p className="mt-1 font-heading font-semibold text-neutral-900 text-sm sm:text-lg leading-snug break-words [overflow-wrap:anywhere]">
                  {pick(stage.nameEn, stage.nameNe)}
                </p>

                <div className="mt-1 flex flex-wrap items-center gap-x-3 gap-y-1 text-xs text-neutral-500">
                  {stage.location && (
                    <span className="inline-flex min-w-0 items-start gap-1">
                      <MapPin className="h-3.5 w-3.5 flex-shrink-0" />
                      <span className="break-words [overflow-wrap:anywhere]">{stage.location}</span>
                    </span>
                  )}
                  {typeof stage.baselineMinutes === "number" && (
                    <span className="inline-flex min-w-0 items-start gap-1">
                      <Loader className="h-3.5 w-3.5 flex-shrink-0" />
                      {t("services.roadmap.baselineMinutes", { n: stage.baselineMinutes })}
                    </span>
                  )}
                </div>


                <RequiredDocumentsList stage={stage} />
              </div>
            </li>
          );
        })}
      </ol>
    </section>
  );
};

export default ServiceRoadmap;
