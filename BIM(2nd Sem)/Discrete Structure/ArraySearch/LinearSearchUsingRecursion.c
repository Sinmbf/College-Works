// Linear search => search every data one by one (ascending or descending)
// Recursion => an object calls itself
// Principle of recursive function => keep on reducing the function into simpler
//										terms

#include<stdio.h>

int LinearSearch(int arr[],int size, int key) {
	if(size>=0) {
		if(arr[size]==key) {
			return size;
		} else {
			return LinearSearch(arr,size-1,key);
		}
	} else {
		return -1;
	}
}

void main() {
	int arr[]= {50,0,2,30,56,89,11,20,3,4};
	int size=sizeof(arr)/sizeof(arr[0]);  // Find the size of the array
	int key;
	printf("Enter a key to search: ");
	scanf("%d",&key);
	int res=LinearSearch(arr,size-1,key);
	if(res==-1){
		printf("%d not found in array",key);
	}
	else{
		printf("%d found at index %d",key,res);
	}
}