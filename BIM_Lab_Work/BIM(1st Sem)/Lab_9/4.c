// 4. Modify question number 3 and display the information of Employees having salary greater
// than 15000.

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
	printf("\nEmployees having salary greater than 15000:\n");
	printf("EID  Full Name           Post      Salary\n");
	i=0;
	while(i<5) {
		if(emp[i].emp_salary>15000) {
			printf("%-5d%-20s%-10s%.2f\n",emp[i].emp_id,emp[i].emp_name,emp[i].emp_post,emp[i].emp_salary);
		}
		i++;
	}
}
