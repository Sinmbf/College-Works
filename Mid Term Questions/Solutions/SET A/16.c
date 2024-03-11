// 16. Write a function that accepts two numbers and if the first number is greater than the 
// second number, it should display the difference between them. Otherwise, it should display 
// the sum of the two numbers. Ensure that your program is structured to use a function for the
// calculation.

#include<stdio.h>

// Function Prototype
void sum_diff(int,int);

// Main Function
void main(){
	int n1,n2,result;
	printf("Enter two numbers: ");
	scanf("%d%d",&n1,&n2);
	sum_diff(n1,n2);
}

// Function Definition
void sum_diff(int n1,int n2){
	if(n1>n2){
		printf("%d - %d = %d",n1,n2,n1-n2);
	}
	else{
		printf("%d + %d = %d",n1,n2,n1+n2);
	}
}


