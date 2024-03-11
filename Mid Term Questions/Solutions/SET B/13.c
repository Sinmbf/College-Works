// 13. Write a program that takes an integer number from user, and displays message welcome
// if the given integer number if of four digits only otherwise displays rejected.

#include<stdio.h>

void main(){
	int n,count=0;
	printf("Enter a number: ");
	scanf("%d",&n);
	while(n!=0){
		count++;
		n/=10;
	}
	if(count==4){
		printf("Welcome");
	}
	else{
		printf("Rejected");
	}
}
