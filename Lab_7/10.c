// WAP that calls a function whose name is reverse() that takes number as argument and returns
// the number in reverse order.

// Argument and return type

#include<stdio.h>

int reverse(int);

void main(){
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	printf("The reverse of %d is %d",n,reverse(n));
}

int reverse(int n){
	int rem,rev=0;
	while(n!=0){
		rem=n%10;
		rev=rev*10+rem;
		n/=10;
	}
	return rev;
}
