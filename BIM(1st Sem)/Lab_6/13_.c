// WAP that will take a string and convert the string to uppercase if the first character
// is lowercase and vice versa

#include<stdio.h>

void main() {
	char str[100];
	int i,flag=0;
	printf("Enter a word or sentence: ");
	gets(str);
	for(i=0; str[i]!='\0'; i++) {
		if(str[0]>='A' && str[0]<='Z') {
			str[i]+=32;
		}
		else{
			str[i]-=32;
		}
	}
	printf("%s",str);
}
