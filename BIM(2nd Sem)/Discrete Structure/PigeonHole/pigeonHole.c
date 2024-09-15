#include<stdio.h>

void pigeonHole_sort(int arr[],int n){
	// Find the minimum and maximum values in the input array
<<<<<<< HEAD
	int min_val=arr[0],max_val=arr[0];
	for(int i=1;i<n;i++){
=======
	int i,min_val=arr[0],max_val=arr[0];
	for(i=1;i<n;i++){
>>>>>>> 0cf41913e859f782c6f8dfd6e72496e4ada4307f
		if(arr[i]<min_val){
			min_val=arr[i];
		}
		if(arr[i]>max_val){
			max_val=arr[i];
		}
	}
<<<<<<< HEAD
	int range_size=max-val-min_val+1;
	int pigeonHoles[range_size];
	for(int i=0;i<range_size;i++){
=======
	int range_size=max_val-min_val+1;
	int pigeonHoles[range_size];
	for(i=0;i<range_size;i++){
>>>>>>> 0cf41913e859f782c6f8dfd6e72496e4ada4307f
		pigeonHoles[i]=0;
	}
	
	// Distribute elements into pigeonholes
<<<<<<< HEAD
	for(int i=0;i<n;i++){
=======
	for(i=0;i<n;i++){
>>>>>>> 0cf41913e859f782c6f8dfd6e72496e4ada4307f
		pigeonHoles[arr[i] - min_val]++;
	}
	
	// Reconstruct the sorted array from pigeonholes
	int index=0;
<<<<<<< HEAD
	for(int i=0;i<range_size;i++){
=======
	for(i=0;i<range_size;i++){
>>>>>>> 0cf41913e859f782c6f8dfd6e72496e4ada4307f
		while(pigeonHoles[i]>0){
			arr[index]=i+min_val;
			index++;
			pigeonHoles[i]--;
		}
	}
}

int main(){
<<<<<<< HEAD
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
=======
	int i,arr[]={8,3,2,7,4,6,8};
	int n=sizeof(arr)/sizeof(arr[0]);
	int pigeonHoles;
	printf("Original Array\n");
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	}
	pigeonHole_sort(arr,n);
	printf("\n Sorted array: \n");
	for(i=0; i<n;i++){
		printf("%d",arr[i]);
	}
	return 0;
}
>>>>>>> 0cf41913e859f782c6f8dfd6e72496e4ada4307f
