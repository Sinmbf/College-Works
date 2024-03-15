// 4. WAP that takes an input from user and then checks whether it is a number or character.

#include<stdio.h>

void main(){
	char ch,*ptr;
	printf("Enter something: ");
	scanf("%c",&ch);
	ptr=&ch;
	if(*ptr>='0' && *ptr<='9'){
		printf("%c is number",*ptr);
	}
	else{
		printf("%c is a character",*ptr);
	}
}
