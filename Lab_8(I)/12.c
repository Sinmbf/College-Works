// 12. WAP that can find the largest of number of an array using user defined function
// called largest with following prototype: int largest(int *);

#include<stdio.h>

// Function Prototype
int largest(int *);

// Main Program
void main(){
	int a[5],*ptr,i,maximum;
	ptr=a;
	printf("Enter 5 values: ");
	for(i=0;i<5;i++){
		scanf("%d",ptr+i);
	}
	maximum=largest(ptr);
	printf("Largest element: %d",maximum);
}

// Function Definition
int largest(int *ptr){
	int i,greatest=*ptr;
	for(i=1;i<5;i++){
		if(*(ptr+i)>greatest){
			greatest=*(ptr+i);
		}
	}
	return greatest;
}
