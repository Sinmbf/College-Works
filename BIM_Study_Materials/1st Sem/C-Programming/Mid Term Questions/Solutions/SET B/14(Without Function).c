// 14. WAP to check whether the string inputted by user is palindrome or not.

#include<stdio.h>

void main(){
	char str[50],org[50],temp;
	int i,len=0,flag=1;
	printf("Enter a word or sentence: ");
	gets(str);
	// Copy string to another variable and find the length of the string
	for(i=0;str[i]!='\0';i++){
		org[i]=str[i];
		len++;
	}
	// Reverse the given string
	i=0;
	len=len-1;
	while(i<len){
		temp=str[i];
		str[i]=str[len];
		str[len]=temp;
		i++;
		len--;
	}
	// Check if palindrome or not
	for(i=0;str[i]!='\0';i++){
		if(str[i]!=org[i]){
			flag=0;
			break;
		}
	}
	if(flag==1){
		printf("Palindrome");
	}
	else{
		printf("Not Palindrome");
	}
	
}
