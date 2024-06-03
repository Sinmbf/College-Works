// 3. WAP to calculate the nth element of the fiboncacci sequence using recursive
// function.

#include<stdio.h>

// Function Prototype
int fibonacci(int);

// Main Program
void main(){
	int n,i,res;
	printf("Enter the number of terms: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		res=fibonacci(i);
		printf("%d\n",res);
	}
}

// Function Definition
int fibonacci(int n){
	if(n==0 || n==1){
		return n;
	}
	return fibonacci(n-1)+fibonacci(n-2);
}
