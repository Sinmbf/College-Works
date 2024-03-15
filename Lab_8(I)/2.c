// 2. WAP that can accept the content of two numbers and perform addition, subtraction,
// and multiplication between them using pointer.

#include<stdio.h>

void main(){
	int n1,n2,*ptr1,*ptr2;
	printf("Enter two numbers: ");
	scanf("%d%d",&n1,&n2);
	ptr1=&n1;
	ptr2=&n2;
	printf("%d + %d = %d\n",*ptr1,*ptr2,*ptr1+*ptr2);
	printf("%d - %d = %d\n",*ptr1,*ptr2,*ptr1-*ptr2);
}
