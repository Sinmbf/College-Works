#include<stdio.h>

void main(){
	int arr[5],e[5],o[5],i,count1=0,count2=0;
	printf("Enter 5 elements: ");
	for(i=0;i<5;i++){
		scanf("%d",&arr[i]);
		if(arr[i]%2==0){
			e[count1]=arr[i];
			count1++;
		}
		else{
			o[count2]=arr[i];
			count2++;
		}
	}
	printf("Even elements in the array:\n");
	for(i=0;i<count1;i++){
		printf("%d\n",e[i]);
	}
	printf("Odd elements in the array:\n");
	for(i=0;i<count2;i++){
		printf("%d\n",o[i]);
	}
	
}
