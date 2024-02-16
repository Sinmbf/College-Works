#include<stdio.h>

void main(){
	int n1,n2;
	printf("Enter two numbers: ");
	scanf("%d%d",&n1,&n2);
	printf("The sum of squares of %d and %d is %d",n1,n2,(n1*n1*n1)+(n2*n2*n2));
}
