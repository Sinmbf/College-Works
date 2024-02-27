// WAP that will examine each character in a character array and count how many 'a' characters
// are there.

#include<stdio.h>

void main(){
	char a[100],i,count=0;
	printf("Enter a sentence: ");
	gets(a);
	for(i=0;a[i]!='\0';i++){
		if(a[i]=='a' || a[i]=='A'){
			count++;
		}
	}
	printf("Number of \'a\' characters: %d",count);
}
