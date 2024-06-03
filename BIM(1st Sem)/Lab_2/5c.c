// WAP to read two numbers. If first is greater than the second number, 
// then display its difference else display the sum of them

#include<stdio.h>

void main(){
	int n1,n2;
	printf("Enter first number: ");
	scanf("%d",&n1);
	printf("Enter second number: ");
	scanf("%d",&n2);
	// Using Ternary Operator
	/*
	(n1>n2)
		?printf("The difference of %d and %d is %d\n",n1,n2,n1-n2)
		:printf("The sum of %d and %d is %d\n",n1,n2,n1+n2);
	*/
	// Using if and if else
	if(n1>n2){
		printf("The difference of %d and %d is %d\n",n1,n2,n1-n2);
	}
	else{
		printf("The sum of %d and %d is %d\n",n1,n2,n1+n2);
	}
}
