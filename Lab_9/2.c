// 2. WAP to create a structure named Employee having members emp_id, emp_name, emp_post
// and emp_salary. Read the data of an employee and display it on screen.

#include<stdio.h>

struct Employee{
	int emp_id;
	char emp_name[20];
	char emp_post[10];
	float emp_salary;
}emp;

void main(){
	printf("Enter the details of the employee:\n");
	printf("Employee ID: ");
	scanf("%d",&emp.emp_id);
	fflush(stdin);
	printf("Name: ");
	gets(emp.emp_name);
	printf("Post: ");
	gets(emp.emp_post);
	printf("Salary: ");
	scanf("%f",&emp.emp_salary);
	printf("Details of employee %s:\n",emp.emp_name);
	printf("EID  Name                Post      Salary\n");
	printf("%-5d%-20s%-10s%.2f\n",emp.emp_id,emp.emp_name,emp.emp_post,emp.emp_salary);
}
