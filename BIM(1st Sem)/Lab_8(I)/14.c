// 14. WAP that can perform C=A+B where A, B and C are 1-D array of size 10 using user 
// defined function called add with following prototype: void add(int *at,int *bt,int *ct)

#include<stdio.h>

// Function Prototype
void add(int *at,int *bt,int *ct);

// Main Program
void main(){
	int i,a[10],b[10],c[10],*at,*bt,*ct;
	at=a;
	bt=b;
	ct=c;
	printf("Enter 10 values for array A: ");
	for(i=0;i<10;i++){
		scanf("%d",at+i);
	}
	printf("Enter 10 values for array B: ");
	for(i=0;i<10;i++){
		scanf("%d",bt+i);
	}
	add(at,bt,ct);	
}

// Function Definition
void add(int *at,int *bt,int *ct){
	int i;
	for(i=0;i<10;i++){
		*(ct+i)=*(at+i)+*(bt+i);
	}
	printf("C = A + B:\n");
	for(i=0;i<10;i++){
		printf("%d\n",*(ct+i));
	}
}
