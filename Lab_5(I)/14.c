#include<stdio.h>

void main(){
	int n,i,sum=0,min,max;
	float avg;
	printf("How many people's age do you want to enter? ");
	scanf("%d",&n);
	int a[n];
	printf("Enter age of %d people: ",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	avg=(float)sum/n;
	min=a[0];
	max=a[1];
	for(i=0;i<n;i++){
		if(a[i]>max){
			max=a[i];
		}
		if(a[i]<min){
			min=a[i];
		}
	}
	printf("Minimum Age: %d\nMaximum Age: %d\nAverage age of %d people: %g",min,max,n,avg);
}
