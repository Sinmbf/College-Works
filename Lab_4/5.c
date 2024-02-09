#include<stdio.h>

void main() {
	int i=1,sum1=0,sum2=0;
	do{
		if(i%2==0) {
			sum1+=i;

		} else {
			sum2+=i;

		}
		i++;
	}while(i<=100);
	printf("The sum of even numbers from 1 to 100 = %d\n",sum1);
	printf("The sum of odd numbers from 1 to 100 = %d\n",sum2);
}
