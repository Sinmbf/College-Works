// WAP to read array of 5 numbers and display largest and smallest number. Define read()
// function to read numbers, largest() to find the largest and smallest() to find the
// smallest number.

#include<stdio.h>

// Function Prototype
int read();
void largest(int []);
void smallest(int []);

// Main Function
void main(){
	int i,a[5],greatest,least;
	printf("Enter 5 numbers: ");
	for(i=0;i<5;i++){
		a[i]=read();
	}
	largest(a);
	smallest(a);
}

// Function Definition
int read(){
	int n;
	scanf("%d",&n);
	return n;
}

void largest(int a[5]){
	int i,largest=a[0];
	for(i=0;i<5;i++){
		if(a[i]>largest){
			largest=a[i];
		}
	}
	printf("Largest element: %d\n",largest);
}

void smallest(int a[5]){
	int i,smallest=a[0];
	for(i=0;i<5;i++){
		if(a[i]<smallest){
			smallest=a[i];
		}
	}
	printf("Smallest element: %d\n",smallest);
}
