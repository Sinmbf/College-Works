#include<stdio.h>

void main(){
	int i,factorial=1;
	float sum=0;
	for(i=1;i<=7;i++){
		factorial*=i;
		sum+=(float)i/factorial;
	}
	printf("The sum of first seven terms of the given series is %.2f",sum);
}
