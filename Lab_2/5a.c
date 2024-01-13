// WAP to read a number and print whether the number is odd or even

#include<stdio.h>

void main(){
	int num;
	printf("Enter a number: ");
	scanf("%d",&num);
	// Using Ternary Operator
	/*
	(num%2==0)?printf("%d is even\n",num):printf("%d is odd\n",num);
	*/
	// Using if and else if
	if(num%2==0){
		printf("%d is even\n",num);
	}
	else{
		printf("%d is odd\n",num);
	}
}
