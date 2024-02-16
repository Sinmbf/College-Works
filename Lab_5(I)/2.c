#include<stdio.h>

void main(){
	int i,a[5];
	printf("Enter 5 elements: ");
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
	}
	printf("Negative elements in the array:\n");
	for(i=0;i<5;i++){
		if(a[i]<0){
			printf("%d\n",a[i]);
		}
	}
} 
