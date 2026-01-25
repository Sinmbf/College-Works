/* Write a query to create database named "Bim4th" */

CREATE DATABASE Bim4th;

/* Write a query to create a table named employee with attributes (eid,ename,address,phone) */

CREATE TABLE employee(
	eid INT PRIMARY KEY,
	ename VARCHAR(10) NOT NULL,
	address VARCHAR(10),
	phone NUMERIC(10,0)
);

/* Add attribute (column) named, job_status into employee table */

ALTER TABLE employee ADD job_status VARCHAR(1);
ALTER TABLE employee ADD email VARCHAR(20);
ALTER TABLE employee DROP job_status;

DROP TABLE employee;
DESCRIBE employee;

/* Insert details of 5 employees in the employee table */

INSERT INTO employee(eid,ename,address,phone,email)
VALUES(101,"Sinmbf","Dallu",9841829033,"sinmbf@gmail.com"),
(102,"Sinmbf1","Dallu",9841829033,"sinmbf@gmail.com"),
(103,"Sinmbf2","Dallu",9841829033,"sinmbf@gmail.com"),
(104,"Sinmbf3","Dallu",9841829033,"sinmbf@gmail.com"),
(105,"Sinmbf4","Dallu",9841829033,"sinmbf@gmail.com");

SELECT * FROM employee;



