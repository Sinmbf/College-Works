// WAP to read a character and convert it into uppercase if it is in lowercase and vice-versa
// using function with argument and return type

// Argument and return type

#include<stdio.h>

char convert(char);

void main(){
	char ch;
	printf("Enter an alphabet: ");
	scanf("%c",&ch);
	printf("After conversion:\n%c",convert(ch));
}

char convert(char ch){
	if(ch>='A' && ch<='Z'){
		return ch+32;
	}
	else{
		if(ch>='a' && ch<='z'){
			return ch-32;
		}
	}
}
