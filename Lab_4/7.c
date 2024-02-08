#include<stdio.h>

void main(){
	int n1,n2;
	char ch;
	do{
		printf("Enter two numbers: ");
		scanf("%d%d",&n1,&n2);
		printf("%d + %d = %d\n",n1,n2,n1+n2);
		printf("Do you want to continue? [y/n]: ");
		scanf(" %c",&ch);
	}while(ch=='y' || ch=='Y');
}
