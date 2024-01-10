// WAP to read two numbers and display the greatest of them

#include<stdio.h>

void main(){
	int n1,n2;
	printf("Enter first number: ");
	scanf("%d",&n1);
	printf("Enter second number: ");
	scanf("%d",&n2);
	// Using Ternary Operator
	/*
	(n1>n2)?printf("%d is the greatest\n",n1):printf("%d is the greatest\n",n2);
	*/
	// Using if and else if
	if(n1>n2){
		printf("%d is the greatest\n",n1);
	}
	else{
		printf("%d is the greatest\n",n2);
	}
	
}
