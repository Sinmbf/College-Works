// WAP to read a number 'n' and calculate its cube by using function

// b) Argument and return type

#include<stdio.h>

int cube(int);

void main() {
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	printf("The cube of %d is %d",n,cube(n));
}

int cube(int n) {
	
	return n*n*n;
}
