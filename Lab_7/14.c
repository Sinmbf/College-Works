// WAP that use a function called Armstrong(). This function takes a number as a input and
// check whether it is Armstrong or not.

// Argument but no return type

#include<stdio.h>

void Armstrong(int);

void main(){
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	Armstrong(n);
}

void Armstrong(int n){
	int rem,sum=0,temp=n;
	while(n!=0){
		rem=n%10;
		sum=sum+(rem*rem*rem);
		n/=10;
	}
	if(sum==temp){
		printf("Armstrong");
	}
	else{
		printf("Not armstrong");
	}
}
