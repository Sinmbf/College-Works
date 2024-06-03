#include<stdio.h>

void main(){
	int n,target=0,arr[]={5,3,112,1,43,6},i,num;
	n=sizeof(arr)/sizeof(arr[0]); // Find the number of elements in the array
	printf("Which number do you want to search? ");
	scanf("%d",&num);
	for(i=0;i<n;i++){
		if(arr[i]==num){
			target++;
			printf("A match found at index %d which is %d",i,arr[i]);
			break;
		}
	}
	if(target==0){
		printf("No match found");
	}
	
}
