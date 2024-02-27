// WAP to read array of 5 numbers and display largest and smallest number. Define read()
// function to read numbers, largest() to find the largest and smallest() to find the
// smallest number.

#include<stdio.h>

// Function Prototype
int read();
int largest(int,int);
int smallest(int,int);

// Main Function
void main(){
	int i,a[5],greatest,least;
	printf("Enter 5 numbers: ");
	for(i=0;i<5;i++){
		a[i]=read();
	}
	greatest=a[0];
	least=a[1];
	for(i=0;i<5;i++){
		greatest=largest(greatest,a[i]);
		least=smallest(least,a[i]);
	}
	printf("The largest value in the array: %d\nThe smallest value in the array: %d",greatest,least);
}

// Function Definition
int read(){
	int n;
	scanf("%d",&n);
	return n;
}

int largest(n1,n2){
	if(n2>n1){
		return n2;
	}
	return n1;
}

int smallest(n1,n2){
	if(n2<n1){
		return n2;
	}
	return n1;
}
