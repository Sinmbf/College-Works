// WAP that will take an integer of four digit and display individual number in words

#include<stdio.h>

void main(){
	int n,i=1000,rem,temp;
	printf("Enter a four-digit integer: ");
	scanf("%d",&n);
	temp=n;
	while(n!=0){
		rem=temp/i;
		switch(rem){
			case 0:
				printf("Zero ");
				break;
			case 1:
				printf("One ");
				break;
			case 2:
				printf("Two ");
				break;
			case 3:
				printf("Three ");
				break;
			case 4:
				printf("Four ");
				break;
			case 5:
				printf("Five ");
				break;
			case 6:
				printf("Six ");
				break;
			case 7:
				printf("Seven ");
				break;
			case 8:
				printf("Eight ");
				break;
			case 9:
				printf("Nine ");
				break;
		}
		temp%=i;
		i/=10;
		n/=10;
	}
	
}
