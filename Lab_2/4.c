// WAP to read 4-digit number and find the sum of square of each digit

#include<stdio.h>

void main(){
	int num,cnum,sum=0,rem;
	printf("Enter a four-digit number: ");
	scanf("%d",&num);
	cnum=num;
	rem=num%10;
	sum=rem*rem+sum;
	num=num/10;
	rem=num%10;
	sum=rem*rem+sum;
	num=num/10;
	rem=num%10;
	sum=rem*rem+sum;
	num=num/10;
	rem=num%10;
	sum=rem*rem+sum;
	num=num/10;
	printf("The sum of the squares of each digits of %d is %d\n",cnum,sum);
}
