// WAP that will take an integer of four digits and display individual number in words.

#include<stdio.h>

void main(){
	int n,rem,i=0;
	char str[100];
	printf("Enter a four digit integer: ");
	scanf("%d",&n);
	while(n!=0){
		rem=n%10;
		n/=10;
	}
	printf("%s",str);
}
