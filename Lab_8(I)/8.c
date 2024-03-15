// 8. WAP that can accept the content of two 1-D arrays called A and B of size 10
// using pointer. Perform C=A-B using pointer only, now display the content of C
// array but using pointer.

#include<stdio.h>

void main(){
	int i,a[10],b[10],c[10],*ptr1=a,*ptr2=b,*ptr3=c;
	printf("Enter 10 numbers for array A: ");
	for(i=0;i<10;i++){
		scanf("%d",ptr1+i);
	}
	printf("Enter 10 numbers for array B: ");
	for(i=0;i<10;i++){
		scanf("%d",ptr2+i);
		*(ptr3+i)=*(ptr1+i)+*(ptr2+i);
	}
	printf("C=A+B:\n");
	for(i=0;i<10;i++){
		printf("%d\n",*(ptr3+i));
	}
}
