// 8. WAP that creates a structure called student and store the data.

/*
	a.) Display the data in exact format as given.
	b.) Find the total of each student.
	c.) Display them in descending order in a format similar to above
	d.) Find average marks in Programming
	e.) Find the percentage of Nabaraj
	f.) Display the name of Topper
	g.) Find the average marks of student
*/

#include<stdio.h>
#include<string.h>

struct student {
	int roll;
	char name[20];
	char s_name[20];
	int marks[5];
	int total;
};

void main() {
	struct student s[5],temp[5];
	int i,j,totalInC=0,totalMarksOfAll=0,topper,count=0;
	float avgInC,avgInAll,percentage;
	char sub[5][20]= {"C","English","Mathematics","Foundation of IT","Business Management"};
	// Read values
	for(i=0; i<5; i++) {
		s[i].total=0;
		printf("Enter details of student %d:\n",i+1);
		printf("Roll Number: ");
		scanf("%d",&s[i].roll);
		fflush(stdin);
		printf("First Name: ");
		gets(s[i].name);
		strcat(s[i].name," ");
		printf("Surname: ");
		gets(s[i].s_name);
		printf("Enter marks:\n");
		for(j=0; j<5; j++) {
			printf("In %s: ",sub[j]);
			scanf("%d",&s[i].marks[j]);
			s[i].total+=s[i].marks[j];
		}
		printf("\n");
	}
	// Sorting in descending order
	for(i=0; i<5; i++) {
		for(j=i+1; j<5; j++) {
			if(s[i].total<s[j].total) {
				temp[i]=s[i];
				s[i]=s[j];
				s[j]=temp[i];
			}
		}
	}
	// Display
	printf("Details of students(From highest marks to lowest):\n");
	printf("Roll No  Name                C         English   Math      FIT       Business  Total Marks\n");
	for(i=0; i<5; i++) {
		printf("%-9d%-20s",s[i].roll,strcat(s[i].name,s[i].s_name));
		for(j=0; j<5; j++) {
			printf("%-10d",s[i].marks[j]);
		}
		printf("%-11d",s[i].total);
		printf("\n");
	}
	// Find average marks 
	for(i=0; i<5; i++) {
		totalInC+=s[i].marks[0]; // in C
		totalMarksOfAll+=s[i].total;
	}
	avgInC=(float)totalInC/5;
	avgInAll=(float)totalMarksOfAll/5;
	printf("\nAverage marks in Programming: %.2f\n",avgInC);
	// Find percentage of Nabaraj
	for(i=0; i<5; i++) {
		if(strcmp("Nabaraj Pandey",s[i].name)==0) {
			percentage=(float)s[i].total/500*100;
			printf("\nPercentage of %s: %.2f%%\n",s[i].name,percentage);
			break;
		}
	}
	// Find the topper and display the name
	topper=s[0].total;
	for(i=0;i<5;i++){
		if(s[i].total>topper){
			topper=s[i].total;
			count=i;
		}
	}
	printf("\nTopper: %s\n",s[count].name);
	// Find the average marks of student
	printf("\nAverage marks of students: %.2f\n",avgInAll);
}
