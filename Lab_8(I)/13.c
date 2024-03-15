// 13. WAP that can sort an array in ascending order using user defined function called
// ascending with the following prototype: void ascending(int *);

#include<stdio.h>

// Function Prototype
void ascending(int *);

// Main Program
void main(){
	int a[5],*ptr,i;
	ptr=a;
	printf("Enter 5 values: ");
	for(i=0;i<5;i++){
		scanf("%d",ptr+i);
	}
	ascending(ptr);
}

// Function Definition
void ascending(int *ptr){
	int i,j,temp;
	for(i=0;i<5-1;i++){
		for(j=i+1;j<5;j++){
			if(*(ptr+i)>*(ptr+j)){
				temp=*(ptr+i);
				*(ptr+i)=*(ptr+j);
				*(ptr+j)=temp;
			}
		}
	}
	printf("In Ascending Order:\n");
	for(i=0;i<5;i++){
		printf("%d\n",*(ptr+i));
	}
}
