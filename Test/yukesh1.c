//Write a program that accept information of 10 items and write it to file called c:\\item.txt.
//Use structure for information.
#include<stdio.h>
#include<stdlib.h>
struct student
{
	int roll_no;
	char name[20];
	int age;
}std[10];
void main()
{
	FILE *fp;
	int i;
	printf("Enter any 10 student information\n");
	for(i=0;i<2;i++)
	{
		printf("Enter your Roll no:");
		scanf("%d",&std[i].roll_no);
		printf("Enter your name:");
		fflush(stdin);
		gets(std[i].name);
		printf("Enter your age:");
		scanf("%d",&std[i].age);
	}
	fp=fopen("c:\item.txt","w");
	if(fp==NULL)
	{
		printf("Error on opening file");
		exit(0);
	}
	for(i=0;i<2;i++)
	{
		fprintf(fp,"\n%d\t %s\t %d",std[i].roll_no,std[i].name,std[i].age);
	}
	fclose(fp);
}
