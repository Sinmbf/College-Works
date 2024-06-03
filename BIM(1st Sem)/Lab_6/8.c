// WAP that will examine each character in character type array called text and print out 
// the result by converting upper case into lower case and vice versa.

#include<stdio.h>

void main(){
	char a[100],i;
	printf("Enter a sentence: ");
	gets(a);
	for(i=0;a[i]!='\0';i++){
		if(a[i]>='a' && a[i]<='z'){
			a[i]-=32;
		}
		else{
			if(a[i]>='A' && a[i]<='Z'){
				a[i]+=32;
			}
		}
	}
	printf("%s",a);
}
