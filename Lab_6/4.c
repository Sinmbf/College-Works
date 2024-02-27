// WAP that will examine each character in character type array and determine how many vowels
// and consonants are there

#include<stdio.h>

void main() {
	char a[100],i,vowel=0,cons=0;
	printf("Enter a sentence: ");
	gets(a);
	for(i=0; a[i]!='\0'; i++) {
		if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u') {
			vowel++;
		} else if(a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='O' || a[i]=='U') {
			vowel++;
		} else {
			if(a[i]>'A' && a[i]<='Z' || a[i]>'a' && a[i]<'z') {
				cons++;
			}
		}
	}
	printf("Number of vowels: %d\nNumber of consonants: %d",vowel,cons);
}
