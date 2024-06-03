#include<stdio.h>

void main(){
	int i=1,sum=0,n;
	printf("Enter the number of terms: ");
	scanf("%d",&n);
	while(i<=n){
		sum+=i;
		i++;
	}
	printf("The sum of %d natural numbers = %d\n",n,sum);
}
