#include<stdio.h>

void main() {
	int i=100,n,rem,sum=0;
	printf("Armstrong numbers from 100 to 500:\n\n");
	
	while(i<=500){
		n=i;
		while(n!=0){
			rem=n%10;
			sum+=rem*rem*rem;
			n/=10;
		}
		if(i==sum){
			printf("%d ",i);
		}
		sum=0;
		i++;
	}
}
