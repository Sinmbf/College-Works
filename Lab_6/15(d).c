// WAP to perform the following operations on the strings using <string.h> header file:

/*
	
	d. Swap the two string to each other
	
*/

#include<stdio.h>
#include<string.h>

void main(){
	char str1[100],str2[100],temp[100];
	printf("Enter a string: ");
	gets(str1);
	printf("Enter another string: ");
	gets(str2);
	printf("Before swapping:\nString 1: %s\nString 2: %s\n",str1,str2);
	strcpy(temp,str1);
	strcpy(str1,str2);
	strcpy(str2,temp);
	printf("After swapping:\nString 1: %s\nString 2: %s\n",str1,str2);
}
