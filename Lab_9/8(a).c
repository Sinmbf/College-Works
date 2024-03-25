// 8. WAP that creates a structure called student and store the data.

/*
	a.) Display the data in the given format.
*/

#include<stdio.h>
#include<string.h>

struct student{
	int roll;
	char name[20];
	char s_name[20];
	int marks[5];
	int total;
}s[5];

void main(){
	int i,j;
	char sub[5][20]={"English","C","Foundation of IT","Business Management","Mathematics"};
	printf("Enter details of 5 students:\n");
	for(i=0;i<5;i++){
		printf("Student %d:\n",i+1);
		printf("Roll Number: ");
		scanf("%d",&s[i].roll);
		fflush(stdin);
		printf("First Name: ");
		gets(s[i].name);
		strcat(s[i].name," ");
		printf("Surname: ");
		gets(s[i].s_name);
		printf("Enter marks:\n");
		for(j=0;j<5;j++){
			printf("In %s: ",sub[j]);
			scanf("%d",&s[i].marks[j]);
		}
	}
	printf("Details of students:\n");
	printf("Roll No  Name                C         English   Math      FIT       Business\n");
	for(i=0;i<5;i++){
		printf("%-9d%-20s",s[i].roll,strcat(s[i].name,s[i].s_name));
		for(j=0;j<5;j++){
			printf("%-10d",s[i].marks[j]);
		}
		printf("\n");
	}
}
