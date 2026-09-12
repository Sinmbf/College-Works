import { useTranslation } from 'react-i18next';

export const LanguageSwitcher = () => {
  const { i18n } = useTranslation();
  const isEnglish = i18n.language === 'en';

  return (
    <div className="flex items-center space-x-2">
      <button
        onClick={() => i18n.changeLanguage(isEnglish ? 'ne' : 'en')}
        className="p-2 rounded hover:bg-gray-100 transition-colors"
      >
        {isEnglish ? 'नेपाली' : 'English'}
      </button>
    </div>
  );
};