// 1. WAP to store and print the roll_no, name, age and marks of a student using structure.

#include<stdio.h>

struct student{
	int roll_no;
	char name[20];
	int age;
	float marks;
}s1;

void main(){
	printf("Enter name: ");
	gets(s1.name);
	printf("Enter roll no: ");
	scanf("%d",&s1.roll_no);
	printf("Enter age: ");
	scanf("%d",&s1.age);
	printf("Enter marks: ");
	scanf("%f",&s1.marks);
	printf("Details of %s:\n",s1.name);
	printf("Name                Roll No  Age  Marks\n");
	printf("%-20s%-9d%-5d%.2f\n",s1.name,s1.roll_no,s1.age,s1.marks);
}
