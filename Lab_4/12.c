#include<stdio.h>

void main(){
	int i,n,rem,sum=0,real_n;
	printf("Enter a number: ");
	scanf("%d",&n);
	real_n=n;
	while(n!=0){
		rem=n%10;
		sum+=rem;
		n/=10;
	}
	printf("The sum of each digits of %d is %d",real_n,sum);
}
