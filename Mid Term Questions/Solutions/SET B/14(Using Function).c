// 14. WAP to check whether the string inputted by user is palindrome or not.

#include<stdio.h>
#include<string.h>

void main(){
	char str[50],org[50];
	printf("Enter a word or sentence: ");
	gets(str);
	// Copy string to another variable
	strcpy(org,str);
	// Reverse the given string
	strrev(str);
	// Check if palindrome or not
	if(strcasecmp(org,str)==0){		// strcasecmp checks for both uppercase and lowercase
		printf("Palindrome");
	}
	else{
		printf("Not Palindrome");
	}
	
}
