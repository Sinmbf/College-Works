#include<stdio.h>

void main(){
	int n,real_n,i,rem,rev=0;
	printf("Enter a number: ");
	scanf("%d",&n);
	real_n=n;
	while(n!=0){
		rem=n%10;
		rev=rev*10+rem;
		n/=10;
	}
	if(real_n==rev){
		printf("%d is palindrome\n",real_n);
	}
	else{
		printf("%d is not palindrome\n",real_n);
	}
}
