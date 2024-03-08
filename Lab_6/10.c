// WAP that accepts a sentence of words and counts number of words in the sentence, then
// display each words of the sentence in a different line.

#include<stdio.h>

void main() {
	char a[100];
	int i,count=1;
	printf("Enter a sentence: ");
	gets(a);
	if(a[0]==' ' || a[0]=='\0') {
		count=0;
	} else {
		printf("Words in the sentence:\n");
		for(i=0; a[i]!='\0'; i++) {
			if(a[i]==' ' && a[i+1]!=' '  && a[i+1]!='\0') {
				count++;
			}
			if(a[i]!=' '){
				printf("%c",a[i]);
				if(a[i+1]==' '){
					printf("\n");
				}
			}
		}
	}
	printf("\nNumber of words in the sentence: %d",count);
}
