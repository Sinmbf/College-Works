#include<stdio.h>

void main(){
	char op;
	printf("****Available Operations****\n");
	printf("\nS ==> Save\nO ==> Open\nE ==> Exit\n");
	printf("\n************************\n");
	printf("Enter your choice: ");
	scanf("%c",&op);
	switch(op){
		case 'S':
			printf("Do you want to save the file? ");
			break;
		case 'O':
			printf("Do you want to open the file? ");
			break;
		case 'E':
			printf("Do you want to exit? ");
			break;
		default:
			printf("Invalid Operation!");
	}
}
