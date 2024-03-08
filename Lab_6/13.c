// WAP that takes a string from the user and convert the string into uppercase if the first
// character is lowercase and vice versa.

#include<stdio.h>

void main() {
	char a[100],i;
	int flag=0;
	printf("Enter a sentence: ");
	gets(a);
	if(a[0]>='A' && a[0]<='Z') {
		for(i=0; a[i]!='\0'; i++) {
			if(a[i]>='A' && a[i]<='Z') {
				a[i]+=32;
			}
		}
	} else {
		if(a[0]>='a' && a[0]<='z') {
			for(i=0; a[i]!='\0'; i++) {
				if(a[i]>='a' && a[i]<='z') {
					a[i]-=32;
				}
			}
		}
	}
	printf("%s",a);
}
