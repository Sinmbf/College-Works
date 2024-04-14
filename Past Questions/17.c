// 17. WAP that reads records of 5 employees with fields id, name, department, and salary
// from user and then write the records to the file named "employee.dat". Now display the 
// records of employee whose salary is higher than 30K.

#include<stdio.h>
#include<stdlib.h>

struct employee{
	int id;
	char name[20];
	char department[20];
	int salary;
};

void main(){
	struct employee emp;
	FILE *fptr;
	int i;
	fptr=fopen("employee.dat","wb+");
	if(fptr==NULL){
		printf("Error opening employee.dat");
		exit(1);
	}
	for(i=0;i<5;i++){
		// Taking input from standard input(keyboard)
		printf("Enter details of employee %d:\n",i+1);
		printf("Employee ID: ");
		scanf("%d",&emp.id);
		fflush(stdin);
		printf("Name: ");
		gets(emp.name);
		printf("Department: ");
		gets(emp.department);
		printf("Salary: ");
		scanf("%d",&emp.salary);
		printf("\n");
		fflush(stdin);
		// Writing details into file
		fwrite(&emp,sizeof(emp),1,fptr);
	}
	// Reset the file pointer
	rewind(fptr);
	printf("\nDetails of employees whose salary > 30000:\n");
	printf("Eid  Name           Department     Salary\n");
	while(fread(&emp,sizeof(emp),1,fptr)){
		if(emp.salary>30000){
			printf("%-5d%-15s%-15s%d\n",emp.id,emp.name,emp.department,emp.salary);
		}
	}
	fclose(fptr);
}
