// 12. Write a function with argument and no return type that accepts a number and print
// its factorial.

#include<stdio.h>

// Function Prototype
void factorial(int);

// Main Program
void main(){
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	factorial(n);
}

// Function Definition
void factorial(int n){
	int fact=1,i;
	for(i=1;i<=n;i++){
		fact*=i;
	}
	printf("Factorial of %d = %d",n,fact);
}
