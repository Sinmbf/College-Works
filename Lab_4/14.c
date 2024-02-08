#include<stdio.h>

void main() {
	int i,n,real_i,rem,sum=0;
	printf("Armstrong numbers from 100 to 500:\n\n");
	for(i=100; i<=500; i++) {
		n=i;
		while(n!=0) {
			rem=n%10;
			sum+=(rem*rem*rem);
			n/=10;
		}
		if(i==sum){
			printf("%d\n",i);
		}
		sum=0;
	}
}
