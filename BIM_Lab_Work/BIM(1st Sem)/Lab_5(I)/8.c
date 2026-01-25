#include<stdio.h>

void main(){
	int largest,smallest,i,a[10];
	printf("Enter 10 values: ");
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	largest=a[0];
	smallest=a[0];
	for(i=1;i<10;i++){
		if(a[i]>largest){
			largest=a[i];
		}
		if(a[i]<smallest){
			smallest=a[i];
		}
	}
	printf("The largest element in the array: %d\nThe smallest element in the array: %d",largest,smallest);
}
