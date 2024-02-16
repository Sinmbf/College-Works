#include<stdio.h>

void main(){
	int a[5],i;
	printf("Enter 5 elements: ");
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
	}
	printf("The elements you stored in the array: \n");
	for(i=0;i<5;i++){
		printf("%d\n",a[i]);
	}
}
