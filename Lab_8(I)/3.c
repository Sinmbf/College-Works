// 3. WAP to find the largest number among three numbers using pointer.

#include<stdio.h>

void main(){
	int n1,n2,n3,*ptr1,*ptr2,*ptr3;
	printf("Enter three numbers: ");
	scanf("%d%d%d",&n1,&n2,&n3);
	ptr1=&n1;
	ptr2=&n2;
	ptr3=&n3;
	if(*ptr1>*ptr2 && *ptr1>*ptr3){
		printf("%d is the largest",*ptr1);
	}
	else if(*ptr2>*ptr1 && *ptr2>*ptr3){
		printf("%d is the largest",*ptr2);
	}
	else{
		printf("%d is the largest",*ptr3);
	}
}
