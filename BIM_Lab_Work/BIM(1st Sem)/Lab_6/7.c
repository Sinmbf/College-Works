// WAP that will ask to input a sentence and print the result by replacing the appearance
// of "an" word with "##"

#include<stdio.h>

void main(){
	char a[100];
	int i;
	printf("Enter a line: ");
	gets(a);
	for(i=0;a[i]!='\0';i++){
		if((a[i]=='a' && a[i+1]=='n') || (a[i]=='A' && a[i+1]=='N')){
			a[i]='#';
			a[i+1]='#';
		}
	}
	puts(a);
}
