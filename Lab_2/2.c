// WAP to read character from user in uppercase and change it to lowercase

#include<stdio.h>

void main() {
	char ch;
	printf("Enter a upper case letter: ");
	scanf("%c",&ch);
	printf("%c into lower case is %c\n",ch,ch+32);

}
