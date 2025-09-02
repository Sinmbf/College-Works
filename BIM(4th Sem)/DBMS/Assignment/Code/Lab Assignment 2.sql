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

DROP TABLE student;
TRUNCATE TABLE student;

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
INSERT INTO student (roll, sname, address, phone, cid, email) VALUES
(1, 'Alice', 'Kathmandu', 9800000001, 'BIM', 'alice.@example.com'),
(2, 'Bob', 'Lalitpur', 9800000002, 'BHM', 'bob.@example.com'),
(3, 'Charlie Puth', 'Bhaktapur', 9800000003, 'BCA', 'charlie.@example.com'),
(4, 'David', 'Pokhara', 9800000004, 'BCSIT', 'david.@example.com'),
(5, 'Eva', 'Butwal', 9800000005, 'BBA', 'eva.@example.com'),
(6, 'Fiona', 'Dharan', 9800000006, 'BBA', 'fiona.@example.com'),
(7, 'George', 'Biratnagar', 9800000007, 'BE', 'george.@example.com'),
(8, 'Hannah', 'Janakpur', 9800000008, 'BFA', 'hannah.@example.com'),
(9, 'Ian', 'Nepalgunj', 9800000009, 'BIM', 'ian.@example.com'),
(10, 'Jane', 'Hetauda', 9800000010, 'BHM', 'jane.@example.com'),
(11, 'Kevin', 'Kathmandu', 9800000011, 'BCA', 'kevin.@example.com'),
(12, 'Lily', 'Lalitpur', 9800000012, 'BCSIT', 'lily.@example.com'),
(13, 'Mike', 'Bhaktapur', 9800000013, 'BBA', 'mike.@example.com'),
(14, 'Nina', 'Pokhara', 9800000014, 'BBA', 'nina.@example.com'),
(15, 'Oscar', 'Butwal', 9800000015, 'BE', 'oscar.@example.com'),
(16, 'Penta', 'Dharan', 9800000016, 'BFA', 'pam.@example.com'),
(17, 'Quinn', 'Biratnagar', 9800000017, 'BIM', 'quinn.@example.com'),
(18, 'Ryan', 'Janakpur', 9800000018, 'BHM', 'ryan.@example.com'),
(19, 'Sara', 'Nepalgunj', 9800000019, 'BCA', 'sara.@example.com'),
(20, 'Tom', 'Hetauda', 9800000020, 'BCSIT', 'tom.@example.com');

/* 7. Update faculty column by replacing 'IT' with 'Information Technology' */
UPDATE course SET faculty = 'Information Technology' WHERE faculty = 'IT';

/* 8. Display all records of students who study BIM, BCA, BCSIT */
SELECT * FROM student WHERE cid IN('BIM','BCA','BCSIT');

/* 9. Display records of students whose name ends with 'a' */
SELECT * FROM student WHERE sname LIKE '%a';

/* 10. Display records of students whose name's second last letter is 't' */
SELECT *FROM student WHERE sname LIKE '%t_';

/* 11. Display student details along with course name and faculty as order by the faculty (ascending) */
SELECT s.roll, s.sname, s.address, s.phone, s.email, c.course_name, c.faculty
FROM student AS s
INNER JOIN course AS c
ON s.cid=c.cid
ORDER BY faculty ASC;

/* 12. Perform left outer join, right outer join, full outer join on tables */

SET FOREIGN_KEY_CHECKS = 0;

INSERT INTO student (roll, sname, address, phone, cid, email)
VALUES (21, 'Uma', 'Chitwan', 9800000021, 'BTECH', 'uma.@example.com');

SET FOREIGN_KEY_CHECKS = 1;

SELECT s.roll,s.sname,s.address,s.phone,s.email,c.course_name,c.faculty
FROM student AS s
LEFT OUTER JOIN course AS c
ON s.cid=c.cid;

SELECT s.roll, s.sname, s.cid, c.course_name
FROM student AS s
RIGHT OUTER JOIN course AS c
ON s.cid = c.cid;

SELECT s.roll, s.sname, s.cid, c.course_name
FROM student s
FULL OUTER JOIN course AS c 
ON s.cid = c.cid;

/* 13. Display the course details where no students are enrolled in */
SELECT c.*
FROM student AS s
RIGHT OUTER JOIN course AS c
ON c.cid=s.cid
WHERE s.roll IS NULL;

/* 14. Write SQL code to create view from employee details table. */

CREATE TABLE employee_details (
    emp_id INT PRIMARY KEY,
    emp_name VARCHAR(100),
    department VARCHAR(50),
    salary DECIMAL(10, 2),
    hire_date DATE
);

CREATE VIEW view_employee_summary AS
SELECT emp_name, department, salary
FROM employee_details;

INSERT INTO employee_details (emp_id, emp_name, department, salary, hire_date)
VALUES
    (1, 'Alice Johnson', 'HR', 60000.00, '2022-01-15'),
    (2, 'Bob Smith', 'IT', 75000.00, '2021-11-30'),
    (3, 'Charlie Brown', 'Finance', 72000.00, '2023-03-10');


DROP VIEW view_employee_summary;


/* 15. List data from view. */
SELECT * FROM view_employee_summary;

/* 16. Create view from multiple table and display data. */

CREATE TABLE department_details (
    department_id INT PRIMARY KEY,
    department_name VARCHAR(50)
);

CREATE TABLE employee_details1 (
    emp_id INT PRIMARY KEY,
    emp_name VARCHAR(100),
    department_id INT,
    salary DECIMAL(10, 2),
    hire_date DATE,
    FOREIGN KEY (department_id) REFERENCES department_details(department_id)
);

INSERT INTO department_details VALUES
(10, 'HR'),
(20, 'IT'),
(30, 'Finance');

INSERT INTO employee_details1 VALUES
(1, 'Alice Johnson', 10, 60000.00, '2022-01-15'),
(2, 'Bob Smith', 20, 75000.00, '2021-11-30'),
(3, 'Charlie Brown', 30, 72000.00, '2023-03-10');

CREATE VIEW view_employee_department AS
SELECT 
    e.emp_id,
    e.emp_name,
    d.department_id,
    d.department_name,
    e.salary,
    e.hire_date
FROM employee_details1 AS e
JOIN department_details d ON e.department_id = d.department_id;

DROP VIEW view_employee_department;

/* Display view */
SELECT * FROM view_employee_department;




