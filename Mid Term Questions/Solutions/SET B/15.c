// 15. WAP to find the maximum(largest) element in an array of size n.

#include<stdio.h>

void main(){
	int a[100],i,n,maximum;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("Enter %d values: ",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	maximum=a[0];
	// Find the maximum(largest) element
	for(i=0;i<n;i++){
		if(a[i]>maximum){
			maximum=a[i];
		}
	}
	printf("The maximum element in the array: %d",maximum);
}
