import { useState } from "react";
import { useTranslation } from "react-i18next";
import MainLayout from "../../layouts/MainLayout";
import Card from "../../components/ui/Card";
import Button from "../../components/ui/Button";

export default function CancelToken() {
  const { t } = useTranslation();
  const [done, setDone] = useState(false);
  return (
    <MainLayout>
      <Card className="max-w-md mx-auto mt-10">
        <h2>{t("token.cancel.title", "Cancel Token")}</h2>
        <Button onClick={() => { setDone(true); }}>{t("token.cancel.confirm", "Confirm Cancel")}</Button>
        {done && <p>{t("token.cancel.done", "Cancelled.")}</p>}
      </Card>
    </MainLayout>
  );
}
