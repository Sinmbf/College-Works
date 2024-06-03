// 5. WAP to write a record of employee to file employee.dat using fprintf() function and
// structure.

#include<stdio.h>
#include<stdlib.h>

struct employee{
	char name[20];
	int salary;
}; 

void main(){
	FILE *fptr;
	struct employee e;
	fptr=fopen("employee.txt","wb");
	if(fptr==NULL){
		printf("Error opening employee.dat");
		exit(1);
	}
	printf("Enter employee name: ");
	fgets(e.name,sizeof(e.name),stdin);
	printf("Enter employee salary: ");
	scanf("%d",&e.salary);
	fprintf(fptr,"%s%d",e.name,e.salary);
	printf("Record successfully written into the file");
	fclose(fptr);
}
