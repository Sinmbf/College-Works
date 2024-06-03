// WAP that will examine each character in character type array called text and print result
// by replacing all the vowels by "*" character.

#include<stdio.h>

void main(){
	char a[100],i;
	printf("Enter a sentence: ");
	gets(a);
	for(i=0;a[i]!='\0';i++){
		if(a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='O' || a[i]=='U'){
			a[i]='*';
		}
		else{
			if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u'){
				a[i]='*';
			}
		}
	}
	printf("%s",a);
}
