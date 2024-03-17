// 1. WAP to print your name 10 times using recursive function with static and non-static
// variable.

// Using Non-static variable

#include<stdio.h>

// Function Prototype
void display(int);

// Main Program
void main(){
	int n=10;
	display(n);
}

// Function Definition
void display(int n){
	if(n==0){
		return;
	}
	printf("Sinmbf\n");
	display(n-1);
}
