#include<stdio.h>

void main(){
	int a[5],b[5],i;
	printf("Enter 5 elements: ");
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	printf("Elements of array A copied into array B:\n");
	for(i=0;i<5;i++){
		printf("%d\n",b[i]);
	}
}
