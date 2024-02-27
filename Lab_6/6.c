// WAP that will examine each character in character type array and count how
// many words are there

#include<stdio.h>

void main(){
	char a[5][],i,len=0,count=0;
	printf("Enter a sentence: ");
	for(i=0;i<5;i++){
		gets(a[i]);
	}
	for(i=0;a[i]!='\0';i++){
		count++;
	}
	printf("Number of words in the sentence: %d",count);
}
