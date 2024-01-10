// WAP to find whether the given number is positive or negative

#include<stdio.h>

void main(){
	int num;
	printf("Enter a number: ");
	scanf("%d",&num);
	// Using Ternary Operator
	/*
	(num>0)
		?printf("%d is positive\n",num)
	:(num<0)
		?printf("%d is negative\n",num)
	:(num==0)
		?printf("%d is equal to zero\n",num);	
	*/
	// Using if and if else
	if(num>0){
		printf("%d is positive\n",num);
	}
	else if(num<0){
		printf("%d is negative\n",num);
	}
	else{
		printf("It is equal to zero\n");
	}
}
