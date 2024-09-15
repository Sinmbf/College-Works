#include<stdio.h>
void reverse(int);
void main(){
	int a;
	printf("enter the number");
	scanf("%d",&a);
	reverse(a)
	{
		int rev=0,rem;
		while(x!==0)
		{
			rem=x%10;
			rev=rev*10+rem;
			x=x/10;
		}
		printf("the reversed number is %d",rev);
	}
}