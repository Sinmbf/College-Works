// WAP to read two arrays, add two arrays and store the result in third array and display
// the array. Define read() to read data, sum() to add the array elements and display() to 
// display the final result.

#include<stdio.h>

// Function Prototype
void read(int arr[]);
void sum(int arr1[],int arr2[]);
void display(int arr[]);

// Main Function
void main(){
	int a[5],b[5];
	read(a);
	read(b);
	sum(a,b);	
}

// Function Definition
void read(int arr[5]){
	int i;
	printf("Enter 5 numbers for array: ",i);
	for(i=0;i<5;i++){
		scanf("%d",&arr[i]);
	}
}

void sum(int arr1[5],int arr2[5]){
	int i,res[5];
	for(i=0;i<5;i++){
		res[i]=arr1[i]+arr2[i];
	}
	display(res);
}

void display(int arr[5]){
	int i;
	printf("Sum of two arrays:\n");
	for(i=0;i<5;i++){
		printf("%d\n",arr[i]);
	}
}
