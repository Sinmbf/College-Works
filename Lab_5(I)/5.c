#include<stdio.h>

void main(){
	int i,a[5],count=0;
	printf("Enter 5 elements: ");
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
		if(a[i]>0){
			count++;
		}
	}
	printf("The number of positive elements in the array: %d",count);
}
