#include<stdio.h>

void main(){
	int n,i,a[10];
	printf("How many values do you want to enter[max 10]? ");
	scanf("%d",&n);
	printf("Enter %d values: ",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("The values you entered in reverse order:\n");
	for(i=n-1;i>=0;i--){
		printf("%d\n",a[i]);
	}
}
