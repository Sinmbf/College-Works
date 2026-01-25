// WAP to read character from user in lowercase and change it to uppercase

#include<stdio.h>

void main() {
	char lch,uch;
	printf("Enter a lower case letter: ");
	scanf("%c",&lch);
	uch=lch-32;
	printf("%c into upper case is %c\n",lch,uch);

}
