import express from 'express';
import app from './app';
import dotenv from 'dotenv';
import { PrismaClient } from '@prisma/client';

dotenv.config();

const prisma = new PrismaClient();

prisma.$connect()
  .then(() => console.log('Connected to Prisma database'))
  .catch((error) => console.error('Prisma connection error:', error));

const PORT = process.env.PORT || 5000;

app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});