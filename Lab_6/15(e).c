// WAP to perform the following operations on the strings using <string.h> header file:

/*
	
	e. Compare the two strings.
	
*/

#include<stdio.h>
#include<string.h>

void main(){
	char str1[100],str2[100],temp[100];
	printf("Enter a word: ");
	gets(str1);
	printf("Enter another word: ");
	gets(str2);
	if(strcasecmp(str1,str2)==0){
		printf("They are identical");
	}
	else if(strcasecmp(str1,str2)>0){
		printf("The ASCII value of the first string is greater");
	}
	else{
		printf("The ASCII value of the second string is greater");
	}
}
