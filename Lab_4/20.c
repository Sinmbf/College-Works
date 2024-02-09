#include<stdio.h>

void main(){
	int i,j,n,sum=0;
	printf("Enter the first term: ");
	scanf("%d",&i);
	printf("Enter the no. of terms: ");
	scanf("%d",&n);
	for(j=i;j<=n;j++){
		sum+=j;
	}
	printf("Sum of consecutive terms from %d - %d is %d",i,n,sum);
}
