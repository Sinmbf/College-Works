// 14. WAP to create a file named "employeeinfo.dat" and store records of N employee in the
// file. These records contain name, identification number, office name, and occupation of
// the employee. Also display name of those employees whose office name is "Nccs College"
// and occupation is "manager"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee {
	char name[20];
	int eid;
	char officeName[20];
	char occupation[20];
};

void main() {
	struct employee emp;
	FILE *fptr;
	char ch;
	fptr=fopen("employeeinfo.dat","wb+");
	if(fptr==NULL) {
		printf("Error opening employeeinfo.dat");
		exit(1);
	}
	do {
		// Reading from standard input(keyboard)
		printf("Enter details of employee:\n");
		printf("Name: ");
		gets(emp.name);
		printf("Employee id: ");
		scanf("%d",&emp.eid);
		fflush(stdin);
		printf("Office Name: ");
		gets(emp.officeName);
		printf("Occupation: ");
		gets(emp.occupation);
		// Writing into file
		fwrite(&emp,sizeof(emp),1,fptr);
		printf("\nDo you want to add more?[y/n] ");
		scanf(" %c",&ch);
		fflush(stdin);
		printf("\n");
	} while(ch=='y' || ch=='Y');
	printf("Records added successfully\n");
	// Reset the file pointer
	rewind(fptr);
	printf("\nEmployees whose office name is Nccs College and occupation is manager:\n");
	printf("Eid  Name           Office Name  Occupation\n");
	// Reading from the file
	while(fread(&emp,sizeof(emp),1,fptr)) {
		if((strcasecmp(emp.officeName,"Nccs College")==0) && (strcasecmp(emp.occupation,"Manager")==0)) {
			printf("%-5d%-15s%-13s%s\n",emp.eid,emp.name,emp.officeName,emp.occupation);
		}
	}
	fclose(fptr);
}
