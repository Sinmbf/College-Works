// WAP that calls a function named interest(). This function takes the values of principal, 
// number of years and rate of interest as an argument and returns the calculated interest.

// Argument and return type

#include<stdio.h>

float interest(int,int,int);

void main(){
	int p,t,r;
	printf("Enter principal: ");
	scanf("%d",&p);
	printf("Enter time: ");
	scanf("%d",&t);
	printf("Enter rate of interest: ");
	scanf("%d",&r);
	printf("The simple interest is %.2f",interest(p,t,r));
}

float interest(int p,int t,int r){
	return (float)(p*t*r)/100;
}
