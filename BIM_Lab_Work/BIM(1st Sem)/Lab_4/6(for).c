#include<stdio.h>

void main(){
	int i,sum=0,n;
	printf("Enter the number of terms: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		sum+=i;
	}
	printf("The sum of %d natural numbers = %d\n",n,sum);
}
