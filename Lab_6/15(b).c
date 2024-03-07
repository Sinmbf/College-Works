// WAP to perform the following operations on the strings using <string.h> header file:

/*
	
	b. Concatenate the one string to another string
	
*/

#include<stdio.h>
#include<string.h>

void main(){
	char str1[100],str2[100];
	printf("Enter a string: ");
	gets(str1);
	printf("Enter another string: ");
	gets(str2);
	strcat(str1,str2);
	printf("Concatenated string: %s",str1);
}
