// WAP that reads the marks of a student in seven subjects. 
// Assume total marks of all subjects = 100
// Then calculate the percentage and determine the division using if else if.
// Use these conditions:

/*
	a. Percentage >=80 means distinction
	b. Percentage between 60 and 79 means First Division
	c. Percentage between 45 and 59 means Second Division
	d. Percentage between 32 and 44 means Third Division
	e. Percentage less than or equal to 31 means Fail	
*/

#include<stdio.h>

void main(){
	int m1,m2,m3,m4,m5,m6,m7,total_marks;
	float percentage;
	printf("Enter marks in seven subjects: ");
	scanf("%d%d%d%d%d%d%d",&m1,&m2,&m3,&m4,&m5,&m6,&m7);
	total_marks=m1+m2+m3+m4+m5+m6+m7;
	percentage=(float)(total_marks*100)/700;
	if(percentage>=80){
		printf("Percentage: %.2f%%\nDivision: Distinction\n",percentage);
	}
	else if(percentage>=60){
		printf("Percentage: %.2f%%\nDivision: First Division\n",percentage);
	}
	else if(percentage>=45){
		printf("Percentage: %.2f%%\nDivision: Second Division\n",percentage);
	}
	else if(percentage>=32){
		printf("Percentage: %.2f%%\nDivision: Third Division\n",percentage);
	}
	else{
		printf("Percentage: %.2f%%\nResult: Fail\n",percentage);
	}
}
