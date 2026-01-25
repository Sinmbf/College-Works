#include<stdio.h>

void main(){
	int n1,n2;
	char op;
	printf("Enter any two numbers: ");
	scanf("%d%d",&n1,&n2);
	printf("Which operation do you want to perform? [+,-,*,/,%%]: ");
	scanf(" %c",&op);
	switch(op){
		case '+':
			printf("%d + %d = %d\n",n1,n2,n1+n2);
			break;
		case '-':
			printf("%d - %d = %d\n",n1,n2,n1-n2);
			break;
		case '*':
			printf("%d * %d = %d\n",n1,n2,n1*n2);
			break;
		case '/':
			printf("%d / %d = %.2f\n",n1,n2,(float)n1/n2);
			break;
		case '%':
			printf("%d MOD %d = %d\n",n1,n2,n1%n2);
			break;
		default:
			printf("Invalid operation!");
	}
}
