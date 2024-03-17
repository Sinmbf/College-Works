// 5. WAP to read a line of text and print into reverse order by using recursive function.

#include<stdio.h>
#include<string.h>

// Function Prototype
void reverse(char [],int);

// Main Program
void main(){
	char str[50];
	int len;
	printf("Enter a line of text: ");
	gets(str);
	len=strlen(str);
	reverse(str,len-1);
}

// Function Definition
void reverse(char str[50],int len){
	if(len<0){
		return;
	}
	printf("%c",str[len]);
	reverse(str,len-1);
}
