// WAP that use a function called factorial(). This function takes a number as an argument
// and returns the factorial value of the inputted number.

// Arugment and return type

#include<stdio.h>

int factorial(int);

void main() {
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	if(n<0) {
		printf("Factorial of negative number is undefined");
	} else {
		printf("The factorial of %d is %d",n,factorial(n));
	}
}

int factorial(int n) {
	int i,fact=1;
	for(i=1; i<=n; i++) {
		fact*=i;
	}
	return fact;
}
