// 2. WAP to calculate the factorial of a given number using recursive function.

#include<stdio.h>

// Function Prototype
int factorial(int);

// Main Program
void main(){
	int n,res;
	printf("Enter a number: ");
	scanf("%d",&n);
	res=factorial(n);
	printf("Factorial of %d = %d",n,res);
}

// Function Definition
int factorial(int n){
	if(n==1){
		return n;
	}
	return n*factorial(n-1);
}
