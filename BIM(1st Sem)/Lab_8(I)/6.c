// 5. WAP that can accept the content of 1-D array called A of size 10 using pointer and
// display its content using pointer only.

#include<stdio.h>

void main(){
	int a[10],*ptr,i;
	ptr=a;
	printf("Enter 10 numbers: ");
	for(i=0;i<10;i++){
		scanf("%d",ptr+i);
	}
	printf("The contents:\n");
	for(i=0;i<10;i++){
		printf("%d\n",*(ptr+i));
	}
}
