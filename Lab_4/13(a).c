#include<stdio.h>

void main(){
	int n,real_n,i,rem,sum=0;
	printf("Enter a number: ");
	scanf("%d",&n);
	real_n=n;
	while(n!=0){
		rem=n%10;
		sum+=(rem*rem*rem);
		n/=10;
	}
	if(real_n==sum){
		printf("%d is armstrong\n",real_n);
	}
	else{
		printf("%d is not armstrong\n",real_n);
	}
}
