// 22. WAP to read information from user and display for following structure.

#include<stdio.h>

struct College {
	char college_name[20];
	int ranking;
	struct student {
		int student_id;
		char name[20];
	} s1;
};

int main() {
	struct College clg;
	printf("Enter college name: ");
	gets(clg.college_name);
	printf("Enter ranking: ");
	scanf("%d",&clg.ranking);
	printf("Enter student ID: ");
	scanf("%d",&clg.s1.student_id);
	printf("Enter student name: ");
	fflush(stdin);
	gets(clg.s1.name);
	printf("Student Details:\n");
	printf("Name: %s\nID: %d\nCollege Name: %s\nRanking: %d\n",clg.s1.name,clg.s1.student_id,clg.college_name,clg.ranking);
}
