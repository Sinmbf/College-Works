#include<stdio.h>

void main(){
	int n,i,factorial=1,count=1;
	printf("Enter a number: ");
	scanf("%d",&n);
	if(n>0){
		goto factorial;
	}
	factorial:
		for(i=1;i<=n;i++){
			factorial*=i;
		}
		printf("The factorial of %d is %d",n,factorial);
}
