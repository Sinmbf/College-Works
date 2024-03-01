// WAP that use a function called Armstrong(). This function takes a number as a input and
// check whether it is Armstrong or not.

// Argument but no return type

#include<stdio.h>

void Armstrong(int);
int power(int,int);

void main(){
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	Armstrong(n);
}

void Armstrong(int n){
	int rem,temp,sum=0,count=0;
	temp=n;
	while(n!=0){
		count++;
		n/=10;
	}
	n=temp;
	while(n!=0){
		rem=n%10;
		sum=sum+power(rem,count);
		n/=10;
	}
	if(sum==temp){
		printf("Armstrong");
	}
	else{
		printf("Not armstrong");
	}
}

// Function to calculate power
int power(int b,int p){
	int i,res=1;
	for(i=1;i<=p;i++){
		res*=b;
	}
	return res;
}
