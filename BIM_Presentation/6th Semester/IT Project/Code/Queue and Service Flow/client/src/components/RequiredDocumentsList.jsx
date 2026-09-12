import { useTranslation } from "react-i18next";
import { FileText, ChevronDown, ChevronUp } from "lucide-react";
import { useState } from "react";


const RequiredDocumentsList = ({ stage, inline = false }) => {
  const { t, i18n } = useTranslation();
  const [open, setOpen] = useState(true);
  const isNe = i18n.language === "ne";
  const docs = stage?.documents ?? [];
  const count = docs.length;

  if (count === 0) {
    return (
      <p className="text-xs text-neutral-400 mt-2">{t("services.documents.none")}</p>
    );
  }

  if (inline || count <= 2) {
    return (
      <ul className="mt-2 space-y-2">
        {docs.map((doc) => (
          <li key={doc.id} className="text-xs text-neutral-600 flex items-start gap-2 min-w-0">
            <FileText className="h-3.5 w-3.5 flex-shrink-0 mt-0.5 text-neutral-400" />
            <span className="min-w-0 break-words [overflow-wrap:anywhere] leading-relaxed">{isNe ? doc.nameNe : doc.nameEn}</span>
          </li>
        ))}
      </ul>
    );
  }

  return (
    <div className="mt-3 min-w-0 rounded-xl bg-neutral-50/80 p-2 sm:bg-transparent sm:p-0">
      <button
        type="button"
        onClick={() => setOpen((v) => !v)}
        className="inline-flex w-full sm:w-auto items-center justify-between sm:justify-start gap-1.5 text-xs font-semibold text-primary-700 hover:text-primary-800 px-2 py-1 -ml-2 rounded-md hover:bg-primary-50 transition"
        aria-expanded={open}
      >
        <FileText className="h-3.5 w-3.5" />
        {t("services.documents.countLabel", { count })}
        {open ? <ChevronUp className="h-3.5 w-3.5" /> : <ChevronDown className="h-3.5 w-3.5" />}
      </button>
      {open && (
        <ul className="mt-2 space-y-2 pl-3 border-l-2 border-primary-200">
          {docs.map((doc) => (
            <li key={doc.id} className="text-xs text-neutral-600 flex items-start gap-2 min-w-0">
              <FileText className="h-3.5 w-3.5 flex-shrink-0 mt-0.5 text-neutral-400" />
              <span className="min-w-0 break-words [overflow-wrap:anywhere] leading-relaxed">{isNe ? doc.nameNe : doc.nameEn}</span>
            </li>
          ))}
        </ul>
      )}
    </div>
  );
};

export default RequiredDocumentsList;
