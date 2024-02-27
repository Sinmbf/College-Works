#include<stdio.h>
void main() {
	char sen[30];
	int i;
	printf("Enter a sentence:");
	gets(sen);
	for(i=0; sen[i]!='\0'; i++) {
		if(sen[i]=='A'||sen[i]=='E'||sen[i]=='I'||sen[i]=='O'||sen[i]=='U') {
			sen[i]='*';
		} else {
			if(sen[i]=='a'||sen[i]=='e'||sen[i]=='i'||sen[i]=='o'||sen[i]=='u') {
				sen[i]='*';
			}
		}
	}
	printf("%s",sen);
}
