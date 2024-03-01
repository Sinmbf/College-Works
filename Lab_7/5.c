// WAP to read a number and print its square using function.

// Argument and return type

#include<stdio.h>

int square(int);

void main(){
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	printf("The square of %d is %d",n,square(n));
}

int square(int n){
	return n*n;
}
