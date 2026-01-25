#include<stdio.h>

void main(){
	int i,sum=0,a[5];
	printf("Enter 5 elements: ");
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	printf("The sum of all the elements in the array: %d",sum);
}
