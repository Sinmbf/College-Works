#include<stdio.h>

void main() {
	int a[100],i,j,n,flag=1;
	printf("How many values do you want to enter? ");
	scanf("%d",&n);
	printf("Enter %d values: ",n);
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	printf("Prime numbers in the array: \n");
	for(i=0;i<n;i++){
		flag=1;
		if(a[i]<=1){
			continue;
		}
		for(j=2;j<a[i];j++){
			if(a[i]%j==0){
				flag=0;
				break;
			}
		}
		if(flag){
			printf("%d\n",a[i]);
		}
	}	
}
