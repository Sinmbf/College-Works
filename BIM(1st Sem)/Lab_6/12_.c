// WAP that will take an integer of four digit and diplay individual number in words

#include<stdio.h>
#include<stdlib.h>

void main(){
	int n,i;
	char word[100];
	printf("Enter a four digit integer: ");
	scanf("%d",&n);
	itoa(n,word,10);
	for(i=0;word[i]!='\0';i++){
		switch(word[i]){
			case '0':
				printf("Zero ");
				break;
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
			default:
				printf("Not a number ");
		}
	}
}
