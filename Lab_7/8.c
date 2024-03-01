// WAP that read a number 'n' from user and print your name 'n' times using function with 
// no return type and argument

// No return type and argument

#include<stdio.h>

void print_name(int);

void main(){
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	print_name(n);
}

void print_name(int n){
	int i;
	for(i=0;i<n;i++){
		printf("Sinmbf\n");
	}
}
