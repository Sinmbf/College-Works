1. 
CREATE DATABASE Office_BIM4thB;

2.
CREATE TABLE employee(
eid INT PRIMARY KEY,
ename VARCHAR(20) NOT NULL,
address VARCHAR(15),
gender VARCHAR(5),
department VARCHAR(15),
post VARCHAR(15)
);

3.
ALTER TABLE employee ADD (job_status VARCHAR(1));

4.
CREATE TABLE Salary(
eid INT PRIMARY KEY,
basic_sal INT,
allowance NUMERIC(10,2) DEFAULT 0,
d_allow NUMERIC(10,2) DEFAULT 0,
gross_sal NUMERIC(10,2) DEFAULT 0,
tax NUMERIC(10,2) DEFAULT 0,
net_sal NUMERIC(10,2) DEFAULT 0,
FOREIGN KEY(eid) REFERENCES employee(eid)
);

DESCRIBE Salary;
5.
INSERT INTO employee(eid,ename,address,gender,department,post,job_status)
VALUES(101,"Aman Nepal","Kirtipur","Male","ADMIN","Officer","P"),
(102,"Ram Karki","Lalitpur","Male","ADMIN","Assistant","T"),
(103,"Sita Maharjan","Chitwan","Female","ACC","Officer","T"),
(104,"Bibek Thapa","Kathmandu","Male","ACC","Manager","P"),
(105,"Anju Shrestha","Chitwan","Female","ADMIN","Director","P"),
(106,"Salin Malla","Lalitpur","Male","Sales","Manager","T"),
(107,"Neeta Bista","Kirtipur","Female","Sales","Officer","P"),
(108,"Partham Dangol","Kathmandu","Male","Sales","Assistant","T"),
(109,"Ritesh Basnet","Lalitpur","Male","Store","Officer","P"),
(110,"Bisesh Baskota","Kathmandu","Male","Store","Assistant","P");

6.
INSERT INTO Salary(eid,basic_sal)
VALUES(101,50000),
(102,33000),
(103,50000),
(104,65000),
(105,75000),
(106,65000),
(107,50000),
(108,33000),
(109,50000),
(110,33000);

7.
SELECT * FROM employee WHERE job_status="P";

8.
SELECT *FROM employee WHERE ename LIKE 'A%';

9.
SELECT * FROM employee WHERE ename NOT LIKE 'A%';

10.
SELECT * FROM employee WHERE ename LIKE '__t%';

11.
SELECT * FROM employee WHERE ename LIKE 'B%a';

12.
SELECT * FROM employee WHERE post!="Manager";

13.
UPDATE Salary SET allowance=0.15*basic_sal;

14.
UPDATE Salary AS s
INNER JOIN employee AS e
ON e.eid=s.eid
SET s.d_allow=0.10 * s.basic_sal 
WHERE e.post IN('Manager','Director');

15.
UPDATE Salary SET gross_sal=basic_sal+allowance+d_allow;

16.
UPDATE Salary SET tax=(7.5/100)*gross_sal WHERE gross_sal>60000;

17.
UPDATE Salary SET net_sal=gross_sal-tax;

18.
SELECT e.eid,e.ename,e.post,s.basic_sal,s.allowance,s.d_allow,s.gross_sal,s.tax,s.net_sal
FROM employee AS e
INNER JOIN Salary AS s
ON e.eid=s.eid

19.
SELECT e.eid,e.ename,e.post,s.net_sal
FROM employee AS e
INNER JOIN Salary AS s
ON e.eid=s.eid
WHERE e.post IN('Director','Manager','Officer');

20.
SELECT e.ename,e.post,e.department,s.net_sal
FROM employee AS e
INNER JOIN Salary AS s
ON e.eid=s.eid
ORDER BY e.department ASC;


