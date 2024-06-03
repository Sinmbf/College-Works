#include<stdio.h>

void main(){
	int count=0,total,i,n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	total=n;
	int a[n];
	printf("Enter %d values: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]%2==0){
			count++;
			total--;
		}
	}
	printf("Number of even elements: %d\nNumber of odd elements: %d",count,total);
}
