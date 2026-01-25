// Well Ordering Principle states that in every large number of data, there is a least number.

// WAP to implement the Well-Ordering Principle.
#include<stdio.h>

// Function to find the smallest element in an array
int findSmallest(int arr[],int size){
	if(size<=0){
		printf("Array is empty. Cannot find the smallest element\n");
		return -1;
	}
	int smallest=arr[0];
	for(int i=0;i<size;i++){
		if(arr[i]<smallest){
			smallest=arr[i];
		}
	}
	return smallest;
}

void main(){
	int arr[]={4,5,6,2,3,19,0};
	int size=sizeof(arr)/sizeof(arr[0]);
	int smallestElement;
	smallestElement=findSmallest(arr,size);
	if(smallestElement!=-1){
		printf("Least number exist which is %d. Hence principle verified",smallestElement);
	}
	
}