// WAP that calls a function whose name is mul() that takes one argument and print the 
// multiplication table of inputted number

// Argument and no return type

#include<stdio.h>

void mul(int);

void main(){
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	mul(n);
}

void mul(int n){
	int i;
	printf("Multiplication table of %d:\n",n);
	for(i=1;i<=10;i++){
		printf("%d X %d = %d\n",n,i,n*i);
	}
}
