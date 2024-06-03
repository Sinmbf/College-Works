// 19. WAP to check whether a given number is armstrong or not.

#include<stdio.h>

void main(){
	int n,rem,sum=0,org;
	printf("Enter a number: ");
	scanf("%d",&n);
	org=n;
	while(n!=0){
		rem=n%10;
		sum=sum+(rem*rem*rem);
		n/=10;
	}
	if(org==sum){
		printf("Palindrome");
	}
	else{
		printf("Not Palindrome");
	}
}
