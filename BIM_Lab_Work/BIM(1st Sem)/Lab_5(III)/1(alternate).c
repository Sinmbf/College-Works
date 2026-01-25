// WAP to read array of 5 numbers and display it. Define read() and display() functions
// for the process

#include<stdio.h>

// Function prototype
void read(int a[]);
void display(int a[]);

// Main Function
void main(){
	int a[5];
	// Function call
	read(a);
}

// Function definition
void read(int a[5]){
	int i,n;
	printf("Enter 5 numbers: ");
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
	}
	display(a);
}

void display(int a[5]){
	int i;
	printf("Elements of the array:\n");
	for(i=0;i<5;i++){
		printf("%d\n",a[i]);
	}
}
