// 11. WAP that can swap the content of two variables using user defined function called
// swap with following prototype: void swap(int *,int *)

#include<stdio.h>

// Function Prototype
void swap(int *,int *);

// Main Program
void main(){
	int n1,n2;
	printf("Enter two values: ");
	scanf("%d%d",&n1,&n2);
	printf("Before swap:\nNumber 1 = %d\nNumber 2= %d\n",n1,n2);
	swap(&n1,&n2);
	printf("After swap:\nNumber 1 = %d\nNumber 2= %d\n",n1,n2);
}

// Function Definition
void swap(int *ptr1,int *ptr2){
	int temp;
	temp=*ptr1;
	*ptr1=*ptr2;
	*ptr2=temp;
}
