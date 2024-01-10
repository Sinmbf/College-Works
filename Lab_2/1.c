// WAP to read character from user in lowercase and change it to uppercase

#include<stdio.h>

void main() {
	char ch;
	printf("Enter a lower case letter: ");
	scanf("%c",&ch);
	printf("%c into upper case is %c\n",ch,ch-32);

}
