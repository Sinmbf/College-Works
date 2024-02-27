// WAP to read array of 5 numbers and display it. Define read() and display() functions
// for the process

#include<stdio.h>

// Function prototype
int read();
void display(int);

// Main Function
void main(){
	int i,a[5];
	printf("Enter 5 numbers: ");
	// Function call
	for(i=0;i<5;i++){
		a[i]=read();
	}
	for(i=0;i<5;i++){
		display(a[i]);
	}
}

// Function definition
int read(){
	int n;
	scanf("%d",&n);
	return n;
}

void display(n){
	printf("\n%d\n",n);
}
