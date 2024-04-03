// 13. WAP to create a file named "university.dat". WAP to keep the records of N colleges
// under Tribhuvan University. These records contain name, location and no. of faculties
// of the college. Also display the name of colleges in Kathmandu location.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct college{
	char name[20];
	char location[20];
	int numOfFaculties;
};

void main(){
	struct college clg;
	FILE *fptr;
	char ch;
	fptr=fopen("college.dat","wb+");
	if(fptr==NULL){
		printf("Error opening college.dat");
		exit(1);
	}
	do{
		// Reading from standard input(keyboard)
		printf("Enter details of college:\n");
		printf("Name: ");
		gets(clg.name);
		printf("Location: ");
		gets(clg.location);
		printf("Number of faculties: ");
		scanf("%d",&clg.numOfFaculties);
		printf("\n");
		// Writing into file
		fwrite(&clg,sizeof(clg),1,fptr);
		printf("Do you want to add more?[y/n] ");
		scanf(" %c",&ch);
		fflush(stdin);
		printf("\n");
	}while(ch=='y' || ch=='Y');
	printf("Records added successfully\n");
	// Reset the file pointer
	rewind(fptr);
	// Display college in kathmandu
	printf("\nColleges in Kathmandu:\n");
	printf("Name           Location       No. of faculties\n");
	while(fread(&clg,sizeof(clg),1,fptr)){
		if(strcasecmp(clg.location,"kathmandu")==0){
			printf("%-15s%-15s%d\n",clg.name,clg.location,clg.numOfFaculties);
		}
	}
	fclose(fptr);
}
