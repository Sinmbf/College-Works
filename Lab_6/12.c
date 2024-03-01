// WAP that will take an integer of four digit and display individual number in words

#include<stdio.h>

void main(){
	char n[4];
	int i;
	printf("Enter a four digit number: ");
	gets(n);
	for(i=0;n[i]!='\0';i++){
		switch(n[i]){
			case '1':
				printf("One ");
				break;
			case '2':
				printf("Two ");
				break;
			case '3':
				printf("Three ");
				break;
			case '4':
				printf("Four ");
				break;
			case '5':
				printf("Five ");
				break;
			case '6':
				printf("Six ");
				break;
			case '7':
				printf("Seven ");
				break;
			case '8':
				printf("Eight ");
				break;
			case '9':
				printf("Nine ");
				break;
			case '0':
				printf("Zero ");
				break;
			default:
				printf("\nNot a number\n");
		}
	}
	
}
