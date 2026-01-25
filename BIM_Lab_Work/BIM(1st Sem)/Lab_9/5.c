// 5. WAP to store the roll no. (starting from 1), name and age of 5 students and then
// print the details of the student whose roll no is 2.

#include<stdio.h>

struct student{
	int roll_no;
	char name[20];
	int age;
}std[5];

void main(){
	int i;
	printf("Enter details of student with Roll Number [1-5]:\n");
	for(i=0;i<5;i++){
		printf("Student %d:\n",i+1);
		printf("Roll No: ");
		scanf("%d",&std[i].roll_no);
		fflush(stdin);
		printf("Name: ");
		gets(std[i].name);
		printf("Age: ");
		scanf("%d",&std[i].age);
	}
	printf("Details of student with Roll Number 2:\n");
	printf("Roll No Name              Age\n");
	for(i=0;i<5;i++){
		if(std[i].roll_no==2){
			printf("%-8d%-18s%d\n",std[i].roll_no,std[i].name,std[i].age);
			break;
		}
	}
}
