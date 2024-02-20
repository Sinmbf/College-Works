// WAP that will enter a line of text, store it in an array and then display it backwards

#include<stdio.h>

void main(){
	char a[100],i,len=0;
	printf("Enter a sentence: ");
	gets(a);
	for(i=0;a[i]!='\0';i++){
		len++;
	}
	for(i=len-1;i>=0;i--){
		printf("%c",a[i]);
	}
}
