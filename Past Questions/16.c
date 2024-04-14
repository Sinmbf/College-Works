// 16. A data file "employee.txt" contains name, address and salary of some employees. WAP
// to input a name, search that name in the file and display the record if it exixts.

#include<stdio.h>
#include<stdlib.h>

struct employee {
	char name[20];
	char address[20];
	int salary;
} emp;

void main() {
	FILE *fptr;
	char name[20],ch;
	fptr=fopen("employee.txt","rb");
	if(fptr==NULL) {
		printf("Error opening employee.txt");
		exit(1);
	}

//	do{
//		printf("Enter employee details:\n");
//		printf("Name: ");
//		gets(emp.name);
//		printf("Address: ");
//		gets(emp.address);
//		printf("Salary: ");
//		scanf("%d",&emp.salary);
//		printf("\n");
//		fwrite(&emp,sizeof(emp),1,fptr);
//		printf("Do you want to add more?[y/n]: ");
//		scanf(" %c",&ch);
//		fflush(stdin);
//		printf("\n");
//	}while(ch=='y' || ch=='Y');
//	rewind(fptr);
	printf("Enter a name: ");
	gets(name);
	printf("Searching for record...\n");
	while(fread(&emp,sizeof(emp),1,fptr)) {
		if(strcmp(emp.name,name)==0) {
			printf("Name: %s\nAddress: %s\nSalary: %d\n",emp.name,emp.address,emp.salary);
		}
	}
	fclose(fptr);
}
