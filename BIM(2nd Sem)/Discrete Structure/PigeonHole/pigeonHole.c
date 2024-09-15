#include<stdio.h>

void pigeonHole_sort(int arr[],int n){
	// Find the minimum and maximum values in the input array
	int min_val=arr[0],max_val=arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]<min_val){
			min_val=arr[i];
		}
		if(arr[i]>max_val){
			max_val=arr[i];
		}
	}
	int range_size=max-val-min_val+1;
	int pigeonHoles[range_size];
	for(int i=0;i<range_size;i++){
		pigeonHoles[i]=0;
	}
	
	// Distribute elements into pigeonholes
	for(int i=0;i<n;i++){
		pigeonHoles[arr[i] - min_val]++;
	}
	
	// Reconstruct the sorted array from pigeonholes
	int index=0;
	for(int i=0;i<range_size;i++){
		while(pigeonHoles[i]>0){
			arr[index]=i+min_val;
			index++;
			pigeonHoles[i]--;
		}
	}
}

int main(){
	int arr[]={8,3,2,7,4,6,8};
	int n=sizeof(arr)/sizeof(arr[0]);
	printf("Original Array\n");
	for(int i=0;i<n;i++){
		printf("%d",arr[i]);
	}
	pigeonHoles=sort(arr,n);
	printf("\n Sorted array: \n");
	for(int i=0; i<n;i++){
		printf("%d",arr[i]);
	}
	return 0;
}