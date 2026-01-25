// 11. Write a structure to store the names, salary and hours of work per day of 10 employees
// in a company. Write a program to increase the salary depending on the number of hours
// of work per day as follows and then print the name of all the employees along with their
// final salaries.

/*

	Hours of Work per day	8	10	>=12
	Increase in salary		50	100	150

*/

#include<stdio.h>

struct employee{
	char name[20];
	int salary;
	int hrOfWorkPerDay;
}e[10];

void increaseSalary(struct employee e[]);

void main(){
	int i;
	for(i=0;i<10;i++){
		printf("Enter details of employee %d:\n",i+1);
		printf("Name: ");
		gets(e[i].name);
		printf("Salary: ");
		scanf("%d",&e[i].salary);
		printf("Hours of work per day: ");
		scanf("%d",&e[i].hrOfWorkPerDay);
		fflush(stdin);
	}
	// Function call
	increaseSalary(e);
	// Display the details of employees
	printf("Details of employees:\n");
	printf("Name                Salary  Hours of work per day\n");
	for(i=0;i<10;i++){
		printf("%-20s%-8d%10d\n",e[i].name,e[i].salary,e[i].hrOfWorkPerDay);
	}
}

// Function definition to increase salary
void increaseSalary(struct employee e[10]){
	int i;
	for(i=0;i<10;i++){
		if(e[i].hrOfWorkPerDay==8){
			e[i].salary+=50;
		}
		else if(e[i].hrOfWorkPerDay==10){
			e[i].salary+=100;
		}
		else if(e[i].hrOfWorkPerDay>=12){
			e[i].salary+=150;
		}
	}
}

