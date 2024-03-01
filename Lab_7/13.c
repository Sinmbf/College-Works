// WAP that use a function called prime(). This function takes a number as an argument and return
// 0, if the given argument is prime otherwise 1.

// Argument and return type

#include<stdio.h>

int prime(int);

void main(){
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	printf("Returned value: %d",prime(n));
}

int prime(int n){
	int i,flag=0;
	for(i=2;i<n;i++){
		if(n%i==0){
			flag=1;
			break;
		}
	}
	return flag;
}
