-- Associate queue notifications with the token that triggered them.
-- This prevents a token display page from surfacing another token's notification.
ALTER TABLE "Notification" ADD COLUMN "tokenId" TEXT;

CREATE INDEX "Notification_tokenId_createdAt_idx"
  ON "Notification"("tokenId", "createdAt");

ALTER TABLE "Notification"
  ADD CONSTRAINT "Notification_tokenId_fkey"
  FOREIGN KEY ("tokenId") REFERENCES "Token"("id")
  ON DELETE CASCADE ON UPDATE CASCADE;
