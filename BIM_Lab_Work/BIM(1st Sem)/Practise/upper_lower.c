#include<stdio.h>
void main() {
	char sen[40];
	int i;
	printf("write a sentence:");
	gets(sen);
	for(i=0; sen[i]!='\0'; i++) {
		if(sen[i]>='a' && sen[i]<='z') {
			sen[i]-=32;
		} else if(sen[i]>='A' && sen[i]<='Z') {
			sen[i]+=32;
		}
	}
	printf("%s",sen);

}
