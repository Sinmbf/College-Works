#include<stdio.h>

void main(){
	int n,i,cube;
	printf("Enter a number: ");
	scanf("%d",&n);
	printf("Cube of all numbers from 1-%d which is exactly divisible by 3: \n",n);
	for(i=1;i<=n;i++){
		if(i%3==0){
			printf("%d\n",i*i*i);
		}
	}
}
