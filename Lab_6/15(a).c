// WAP to perform the following operations on the strings using <string.h> header file:

/*
	
	a. Count the number of character in the string
	
*/

#include<stdio.h>
#include<string.h>

void main(){
	char str[100];
	int len;
	printf("Enter a line: ");
	gets(str);
	len=strlen(str);
	printf("The number of characters in the string: %d",len);
}
