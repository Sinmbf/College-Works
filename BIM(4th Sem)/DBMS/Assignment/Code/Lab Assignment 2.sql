/* 1. */
CREATE DATABASE student_mgmtB;
USE student_mgmtB;

/* 2. */
CREATE TABLE course(
cid VARCHAR(5) PRIMARY KEY,
course_name VARCHAR(60) NOT NULL
);


/* 3. */
CREATE TABLE student(
cid VARCHAR(5),
roll INT PRIMARY KEY,
sname VARCHAR(50) NOT NULL,
address VARCHAR(30),
phone NUMERIC(10,0),
FOREIGN KEY(cid) REFERENCES course(cid)
);

/* 4. */
ALTER TABLE student ADD email VARCHAR(35);
ALTER TABLE course ADD faculty VARCHAR(30);

/* 5. */
INSERT INTO course(cid,course_name,faculty)
VALUES('BIM','Bachelors in Information Management','IT'),
('BHM','Bachelors in Hotel Management','Management'),
('BCA','Bachelors in Computer Application','IT'),
('BCSIT','Bachelors in Computer Science & IT','IT'),
('BBM','Bachelors in Business Management','Management'),
('BBA','Bachelors in Business Administration','Management'),
('BE','Bachelors in Engineering','Science'),
('BFA','Bachelors in Fine Arts','Arts');

/* 6. */
INSERT INTO student (roll, sname, address, phone, cid) VALUES
(1, 'Alice', 'Kathmandu', 9800000001, 'BIM'),
(2, 'Bob', 'Lalitpur', 9800000002, 'BHM'),
(3, 'Charlie', 'Bhaktapur', 9800000003, 'BCA'),
(4, 'David', 'Pokhara', 9800000004, 'BCSIT'),
(5, 'Eva', 'Butwal', 9800000005, 'BBM'),
(6, 'Fiona', 'Dharan', 9800000006, 'BBA'),
(7, 'George', 'Biratnagar', 9800000007, 'BE'),
(8, 'Hannah', 'Janakpur', 9800000008, 'BFA'),
(9, 'Ian', 'Nepalgunj', 9800000009, 'BIM'),
(10, 'Jane', 'Hetauda', 9800000010, 'BHM'),
(11, 'Kevin', 'Kathmandu', 9800000011, 'BCA'),
(12, 'Lily', 'Lalitpur', 9800000012, 'BCSIT'),
(13, 'Mike', 'Bhaktapur', 9800000013, 'BBM'),
(14, 'Nina', 'Pokhara', 9800000014, 'BBA'),
(15, 'Oscar', 'Butwal', 9800000015, 'BE'),
(16, 'Pam', 'Dharan', 9800000016, 'BFA'),
(17, 'Quinn', 'Biratnagar', 9800000017, 'BIM'),
(18, 'Ryan', 'Janakpur', 9800000018, 'BHM'),
(19, 'Sara', 'Nepalgunj', 9800000019, 'BCA'),
(20, 'Tom', 'Hetauda', 9800000020, 'BCSIT');






