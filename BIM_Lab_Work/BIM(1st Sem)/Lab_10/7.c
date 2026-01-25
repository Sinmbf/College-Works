// 7. WAP to read and write block of code in/from file using fwrite() and fread() function.

#include<stdio.h>
#include<stdlib.h>

struct student{
	char name[20];
	int age;
	int roll;
};

void main(){
	struct student s,s1;
	FILE *fptr;
	fptr=fopen("file7.txt","wb+");
	if(fptr==NULL){
		printf("Error opening file7.txt");
		exit(1);
	}
	// Reading from standard input(keyboard)
	printf("Enter details of student:\n");
	printf("Name: ");
	gets(s.name);
	printf("Roll No: ");
	scanf("%d",&s.roll);
	printf("Age: ");
	scanf("%d",&s.age);
	// Writing into file
	fwrite(&s,sizeof(s),1,fptr);
	// Reset the file pointer
	rewind(fptr);
	// Reading from the file
	fread(&s1,sizeof(s1),1,fptr);
	// Display into console
	printf("Name: %s\nRoll No: %d\nAge: %d\n",s1.name,s1.roll,s1.age);
	fclose(fptr);
}
