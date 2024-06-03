// 3. Modify question number 2 to read information of 10 Employees and display them.

#include<stdio.h>

struct Employee {
	int emp_id;
	char emp_name[20];
	char emp_post[10];
	float emp_salary;
} emp[10];

void main() {
	int i=0;
	while(i<5) {
		printf("Enter details of Employee %d:\n",i+1);
		printf("Employee ID: ");
		scanf("%d",&emp[i].emp_id);
		fflush(stdin);
		printf("Full Name: ");
		gets(emp[i].emp_name);
		printf("Post: ");
		gets(emp[i].emp_post);
		printf("Salary: ");
		scanf("%f",&emp[i].emp_salary);
		i++;
	}
	printf("EID  Full Name           Post      Salary\n");
	i=0;
	while(i<5) {
		printf("%-5d%-20s%-10s%.2f\n",emp[i].emp_id,emp[i].emp_name,emp[i].emp_post,emp[i].emp_salary);
		i++;
	}
}
