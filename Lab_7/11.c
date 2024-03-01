// WAP that calls a function whose name is palindrome() that takes number as argument and
// check whether it is palindrome or not.

// Argument but no return type

#include<stdio.h>

void palindrome(int);

void main(){
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	palindrome(n);
}

void palindrome(int n){
	int org_n=n,rem,rev=0;
	while(n!=0){
		rem=n%10;
		rev=rev*10+rem;
		n/=10;
	}
	if(org_n==rev){
		printf("Palindrome");
	}
	else{
		printf("Not palindrome");
	}
}
