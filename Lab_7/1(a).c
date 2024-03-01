// WAP to read a number 'n' and calculate its cube by using function

// a) No argument but return type

#include<stdio.h>

int cube();

void main() {
	printf("The cube of %d",cube());
}

int cube() {
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	return n*n*n;
}
