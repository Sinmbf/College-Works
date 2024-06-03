// WAP that will examine how many characters are letters, how many are digits,
// how many are white space characters in a line

#include<stdio.h>

void main() {
	char a[100],i,letter=0,digit=0,white_sp=0;
	printf("Enter a sentence: ");
	gets(a);
	for(i=0; a[i]!='\0'; i++) {
		if((a[i]>='A' && a[i]<='Z') || (a[i]>='a' && a[i]<='z')) {
			letter++;
		} else if(a[i]>='0' && a[i]<='9') {
			digit++;
		} else {
			if(a[i]==' ') {
				white_sp++;
			}
		}
	}
	printf("Letters: %d\nDigits: %d\nWhite Space: %d",letter,digit,white_sp);
}
