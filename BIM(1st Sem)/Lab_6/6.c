// WAP that will examine each character in character type array and count how
// many words are there

#include<stdio.h>

void main() {
	char a[100];
	int i,count=1;
	printf("Enter a sentence: ");
	gets(a);
	if(a[0]==' ' || a[0]=='\0') {
		count=0;
	} else {
		for(i=0; a[i]!='\0'; i++) {
			if(a[i]==' ' && a[i+1]!=' '  && a[i+1]!='\0') {
				count++;
			}
		}
	}
	printf("Number of words in the sentence: %d",count);
}
