import { PrismaClient } from '@prisma/client';
import { hashPassword } from '../src/utils/auth';

const prisma = new PrismaClient();

async function main() {
  // Clear existing data (optional, for clean seed)
  await prisma.$executeRaw`TRUNCATE TABLE "OtpVerification" RESTART IDENTITY CASCADE;`;
  await prisma.$executeRaw`TRUNCATE TABLE "ServiceRequiredDocument" RESTART IDENTITY CASCADE;`;
  await prisma.$executeRaw`TRUNCATE TABLE "RequiredDocument" RESTART IDENTITY CASCADE;`;
  await prisma.$executeRaw`TRUNCATE TABLE "ServiceStage" RESTART IDENTITY CASCADE;`;
  await prisma.$executeRaw`TRUNCATE TABLE "Service" RESTART IDENTITY CASCADE;`;
  await prisma.$executeRaw`TRUNCATE TABLE "GovernmentOffice" RESTART IDENTITY CASCADE;`;
  await prisma.$executeRaw`TRUNCATE TABLE "User" RESTART IDENTITY CASCADE;`;

  // Hash passwords
  const adminPasswordHash = await hashPassword('admin123');
  const staffPasswordHash = await hashPassword('staff123');
  const citizenPasswordHash = await hashPassword('citizen123');

  // Create Government Office
  const office = await prisma.governmentOffice.create({
    data: {
      name: 'Kathmandu Transport Management Office',
      description: 'Office responsible for vehicle registration and driver licensing',
      address: 'Tripureshwor, Kathmandu',
      city: 'Kathmandu',
      district: 'Kathmandu',
      province: 'Bagmati',
      phone: '01-4262020',
      email: 'info@dtmoc.gov.np',
      openingTime: new Date('2026-01-01T09:00:00'),
      closingTime: new Date('2026-01-01T17:00:00'),
      isActive: true,
    },
  });

  // Create Admin User
  const admin = await prisma.user.create({
    data: {
      fullName: 'System Administrator',
      email: 'admin@example.com',
      phone: '9800000001',
      passwordHash: adminPasswordHash,
      role: 'ADMIN',
      preferredLanguage: 'EN',
      isPhoneVerified: true,
      isActive: true,
      officeId: office.id,
    },
  });

  // Create Staff User
  const staff = await prisma.user.create({
    data: {
      fullName: 'Staff Officer',
      email: 'staff@example.com',
      phone: '9800000002',
      passwordHash: staffPasswordHash,
      role: 'STAFF',
      preferredLanguage: 'EN',
      isPhoneVerified: true,
      isActive: true,
      officeId: office.id,
    },
  });

  // Create Sample Citizen User (unverified phone initially)
  const citizen = await prisma.user.create({
    data: {
      fullName: 'Sample Citizen',
      email: 'citizen@example.com',
      phone: '9800000000',
      passwordHash: citizenPasswordHash,
      role: 'CITIZEN',
      preferredLanguage: 'EN',
      isPhoneVerified: false,
      isActive: true,
      officeId: null,
    },
  });

  // Create Service: Driving License
  const service = await prisma.service.create({
    data: {
      officeId: office.id,
      nameEn: 'Driving License',
      nameNe: 'ड्राइभिङ लाइसेन्स',
      descriptionEn: 'Official license to operate motor vehicles in Nepal',
      descriptionNe: 'नेपालमा मोटर सञ्चालन संचालनका अधिकारी लाइसेन्स',
      category: 'Transportation',
      isActive: true,
    },
  });

  // Create Service Stages
  const stagesData = [
    { order: 1, nameEn: 'Application', nameNe: 'आवेदन', descEn: 'Submit application form', descNe: 'आवेदन पत्र प्रस्तुत गर्नु', duration: 10 },
    { order: 2, nameEn: 'Medical Verification', nameNe: 'मेडिकल सत्यापन', descEn: 'Medical fitness test', descNe: 'मेडिकलsuitability परीक्षण', duration: 20 },
    { order: 3, nameEn: 'Office Approval', nameNe: 'कार्यालय स्वीकृति', descEn: 'Approval from transport office', descNe: 'परिवहन कार्यालयबाट अनुमति', duration: 30 },
    { order: 4, nameEn: 'Written Exam', nameNe: 'लिखित परीक्षा', descEn: 'Traffic rules written test', descNe: 'यातायात नियमको लिखित परीक्षा', duration: 45 },
    { order: 5, nameEn: 'Trial', nameNe: 'प्रयोग', descEn: 'Practical driving test', descNe: 'व्यावहारिक ड्राइ빙 परीक्षण', duration: 60 },
    { order: 6, nameEn: 'License Fee', nameNe: 'लाइसेन्स शुल्क', descEn: 'Payment of license fee', descNe: 'लाइसेन्स शुल्कको भुक्तान', duration: 15 },
    { order: 7, nameEn: 'License Generation', nameNe: 'लाइसेन्स तयारी', descEn: 'Printing and issuing license', descNe: 'लाइसेन्स छाप्ने तथा जारी गर्ने', duration: 20 },
  ];

  const stages = await Promise.all(
    stagesData.map((stage) =>
      prisma.serviceStage.create({
        data: {
          serviceId: service.id,
          nameEn: stage.nameEn,
          nameNe: stage.nameNe,
          descriptionEn: stage.descEn,
          descriptionNe: stage.descNe,
          stageOrder: stage.order,
          estimatedDurationMin: stage.duration,
          isActive: true,
        },
      })
    )
  );

  // Create Required Documents
  const docsData = [
    { nameEn: 'Citizenship Certificate', nameNe: 'नागरिकता प्रमाणपत्र', type: 'CitizenshipCertificate', descEn: 'Proof of Nepali citizenship', descNe: 'नेपाली नागरिकताको प्रमाण' },
    { nameEn: 'Application Receipt', nameNe: 'आवेदन रसीद', type: 'ApplicationReceipt', descEn: 'Receipt of submitted application', descNe: ' 제시को आवेदनको रसीद' },
    { nameEn: 'Passport-size Photo', nameNe: 'पासपोर्ट आकारको फोटो', type: 'PassportSizePhoto', descEn: 'Recent passport size photograph', descNe: 'हालको पासपोर्ट आकारको फोटो' },
    { nameEn: 'Medical Report', nameNe: 'मेडिकल प्रतिवेदन', type: 'MedicalReport', descEn: 'Medical fitness certificate from authorized doctor', descNe: 'प्राधिकार प्राप्त डॉक्टरबाट मेडिकल suitability प्रमाणपत्र' },
    { nameEn: 'Payment Receipt', nameNe: 'शुल्क रसीद', type: 'PaymentReceipt', descEn: 'Receipt of paid fees', descNe: 'भुक्तानको रसीद' },
  ];

  const docs = await Promise.all(
    docsData.map((doc) =>
      prisma.requiredDocument.create({
        data: {
          nameEn: doc.nameEn,
          nameNe: doc.nameNe,
          descriptionEn: doc.descEn,
          descriptionNe: doc.descNe,
          documentType: doc.type,
          isActive: true,
        },
      })
    )
  );

  // Link documents to stages (example: all documents required for all stages)
  // In reality, different stages require different docs; for seed we link all to all
  for (const stage of stages) {
    for (const doc of docs) {
      await prisma.serviceRequiredDocument.create({
        data: {
          serviceStageId: stage.id,
          requiredDocumentId: doc.id,
        },
      });
    }
  }

  console.log('Seed data created successfully');
  console.log(`Admin: ${admin.email} / admin123`);
  console.log(`Staff: ${staff.email} / staff123`);
  console.log(`Citizen: ${citizen.email} / citizen123 (phone not verified)`);
}

main()
  .catch((e) => {
    console.error(e);
    process.exit(1);
  })
  .finally(async () => {
    await prisma.$disconnect();
  });