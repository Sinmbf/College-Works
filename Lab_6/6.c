// WAP that will examine each character in character type array and count how
// many words are there

#include<stdio.h>

void main(){
	char a[100],i,len=0,count=0;
	printf("Enter a sentence: ");
	gets(a);
	for(i=0;a[i]!='\0';i++){
		len++;
		if(a[i]==' '){
			count++;
		}	
	}
	printf("Number of words in the sentence: %d",count);
}
