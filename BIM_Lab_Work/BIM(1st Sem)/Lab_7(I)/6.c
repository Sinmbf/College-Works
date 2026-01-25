// WAP to take three numbers and print the largest using function with arugment and return type

// Argument and return type

#include<stdio.h>

int largest(int,int,int);

void main(){
	int n1,n2,n3;
	printf("Enter three numbers: ");
	scanf("%d%d%d",&n1,&n2,&n3);
	printf("The largest among %d, %d and %d is %d",n1,n2,n3,largest(n1,n2,n3));
}

int largest(int n1,int n2,int n3){
	if(n1>n2 && n1>n3){
		return n1;
	}
	else if(n2>n1 && n2>n3){
		return n2;
	}
	else{
		return n3;
	}
}
