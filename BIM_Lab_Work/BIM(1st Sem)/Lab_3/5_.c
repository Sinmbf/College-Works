#include<stdio.h>

void main(){
	int salary;
	float bonus,total_salary;
	char gender;
	printf("Enter the gender of the employee[m/f]:");
	scanf("%c",&gender);
	printf("Enter the salary of the employee: ");
	scanf("%d",&salary);
	if(gender=='m'){
		bonus=0.05*salary;
	}
	else{
		bonus=0.1*salary;
	}
	if(salary<10000){
		bonus+=0.02*salary;
	}
	
	total_salary=salary+bonus;
	printf("Bonus received: %.2f\nTotal_Salary: %.2f\n",bonus,total_salary);
}
