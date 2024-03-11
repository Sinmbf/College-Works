// 17. WAP to check whether a given number is a prime or not.

#include<stdio.h>

void main(){
	int n,flag=1,i;
	printf("Enter a number: ");
	scanf("%d",&n);
	for(i=2;i<n;i++){
		if(n%i==0){
			flag=0;
			break;
		}
	}
	if(flag==1){
		printf("Prime");
	}
	else{
		printf("Not prime");
	}
}
