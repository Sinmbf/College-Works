#include<stdio.h>

void main(){
	int largest,sec_largest,i,a[5];
	printf("Enter 5 elements: ");
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
	}
	largest=a[0];
	sec_largest=a[1];
	for(i=1;i<5;i++){
		if(a[i]>largest){
			sec_largest=largest;
			largest=a[i];
		}
	}
	for(i=0;i<5;i++){
		if(a[i]!=largest && a[i]>sec_largest){
			sec_largest=a[i];
		}
	}
	printf("The second largest element in the array: %d",sec_largest);
}
