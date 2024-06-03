// WAP to perform the following operations on the strings using <string.h> header file:

/*
	
	c. Copy the one string to another string
	
*/

#include<stdio.h>
#include<string.h>

void main(){
	char str1[100],str2[100];
	printf("Enter a string: ");
	gets(str1);
	strcpy(str2,str1);
	printf("Copied string: %s",str2);
}
