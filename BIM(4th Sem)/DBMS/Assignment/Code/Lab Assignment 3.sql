
/* 1. */
CREATE TABLE employee(
	eid INT PRIMARY KEY,
	ename VARCHAR(15),
	did INT,
	salary NUMERIC(10,2),
	joining_date DATE,
	performance_rating CHAR(1),
	FOREIGN KEY(did) REFERENCES department(did)
);

drop table employee;

describe employee;
truncate employee;

/* 2. */
CREATE TABLE department(
	did INT PRIMARY KEY,
	department VARCHAR(50)
);

truncate department;
drop table department;

describe department;

/* 3. */
INSERT INTO department(did,department)
VALUES(100, 'HR'),
(101, 'IT'),	
(102, 'Sales'),
(103, 'Marketing');

/*
8
9
*/

/* 4. */
INSERT INTO employee(eid, ename, did, salary, joining_date, performance_rating)
VALUES(1, 'Alice', 100, 45000, '2020-01-01','A'),
(2, 'Bob', 101, 55000, '2021-02-15', 'B'),
(3, 'Charlie', 102, 48000, '2019-03-20', 'A'),
(4, 'Diana', 103, 5000, '2020-04-10', 'C'),
(5, 'Ethan', 102, 60000, '2021-05-25', 'B'),
(6, 'Fiona', 103, 47000, '2019-01-30', 'A'),
(7, 'George', 100, 44000, '2022-07-12', 'C'),
(8, 'Hannah', 103, 52000, '2021-08-18', 'B'),
(9, 'John', 103, 42000, '2021-08-09', 'A');

select * from employee;

/* 5. */
SELECT ename FROM employee
WHERE did IN (
	SELECT did FROM department WHERE department='Marketing'
);

/* 6.
SELECT ename FROM (
	SELECT * FROM employee
	WHERE performance_rating = 'A' AND salary > 46000
) AS e;
*/

/* 6 no. Better approach */
SELECT ename from employee
WHERE eid IN (
	SELECT eid FROM employee
	WHERE performance_rating = 'A' AND salary > 46000
);
