// WAP that reads two numbers from user and call function add() for addition, subtract() for
// subtraction, product() for multiplication and division() for division

// Argument and return type

#include<stdio.h>

int add(int,int);
int subtract(int,int);
int product(int,int);
float division(int,int);

void main(){
	int n1,n2;
	printf("Enter two numbers: ");
	scanf("%d%d",&n1,&n2);
	printf("%d + %d = %d\n",n1,n2,add(n1,n2));
	printf("%d - %d = %d\n",n1,n2,subtract(n1,n2));
	printf("%d * %d = %d\n",n1,n2,product(n1,n2));
	printf("%d / %d = %.2f\n",n1,n2,division(n1,n2));
}

int add(int n1,int n2){
	return n1+n2;
}

int subtract(int n1,int n2){
	return n1-n2;
}

int product(int n1,int n2){
	return n1*n2;
}

float division(int n1,int n2){
	return (float)n1/n2;
}
