#include<stdio.h>

int secret(char,char*,char*);

int main() {
	char mystr1[]="I like kinneret";
	char mystr2[16];
	int num=secret('e',mystr1,mystr2);
	printf_s("%d\n",num);
	printf_s("%s\n",mystr2);
	return 0;
}

int secret(char c, char* s1, char* s2) {
	if(*s1=='\0') {
		*s2='\0';
		return 0;
	} 
	else {
		if(*s1==c) {
			return 1+secret(c,++s1,s2);
		} else {
			*s2=*s1;
			return secret(c,++s1,++s2);
		}
	}
}

