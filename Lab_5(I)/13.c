#include<stdio.h>

void main(){
	int count1=0,count2=0,i,n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter %d values: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]%2==0){
			count1++;
		}
		else{
			count2++;
		}
	}
	printf("Number of even elements: %d\nNumber of odd elements: %d",count1,count2);
}
