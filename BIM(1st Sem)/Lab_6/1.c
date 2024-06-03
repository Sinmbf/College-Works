// WAP to take a line as input and then display it character wise

#include<stdio.h>

void main(){
	char s[100];
	int i;
	printf("Enter a sentence: ");
	gets(s);
	for(i=0;s[i]!='\0';i++){
		printf("%c",s[i]);
	}
}
