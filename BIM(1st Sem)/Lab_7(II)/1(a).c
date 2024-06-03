// 1. WAP to print your name 10 times using recursive function with static and non-static
// variable.

// Using Static variable

#include<stdio.h>

// Function Prototype
void display();

// Main Program
void main(){
	display();
}

// Function Definition
void display(){
	static int n=1;
	if(n>10){
		return;
	}
	printf("Sinmbf\n");
	n++;
	display();
}
