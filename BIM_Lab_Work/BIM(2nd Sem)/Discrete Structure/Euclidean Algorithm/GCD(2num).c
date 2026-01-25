// WAP to find the GCD of two numbers using Euclidean Algorithm

#include<stdio.h>
void main(){
	int a,b,x,y,z;
	printf("Enter two numbers: ");
	scanf("%d%d",&a,&b);
	x=a;
	y=b;
	while(y!=0){
		z=x%y;
		x=y;
		y=z;
	}
	printf("The GCD of %d and %d is %d\n", a, b, x);
}
