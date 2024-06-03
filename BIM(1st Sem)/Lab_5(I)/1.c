#include<stdio.h>

void main(){
	int n,i;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
}
