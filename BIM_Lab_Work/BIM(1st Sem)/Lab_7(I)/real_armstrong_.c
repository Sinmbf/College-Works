// WAP to check whether a given number is armstrong using function

#include<stdio.h>
#include<math.h>

void Armstrong();

void main(){
	Armstrong();
}

void Armstrong(){
	int n,org,temp,rem,sum=0,count=0;
	printf("Enter a number: ");
	scanf("%d",&n);
	org=temp=n;
	while(n!=0){
		rem=n%10;
		count++;
		n/=10;
	}
	while(temp!=0){
		rem=temp%10;
		sum=sum+pow(rem,count);
		temp/=10;
	}
	if(org==sum){
		printf("Armstrong");
	}
	else{
		printf("Not Armstrong");
	}
}
