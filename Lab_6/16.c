// WAP to sort a list of strings alphabetically using a two dimesional character array

#include<stdio.h>
#include<string.h>

void main() {
	char str[5][10],temp[50];
	int i,j;
	printf("Enter 5 words: ");
	for(i=0; i<5; i++) {
		gets(str[i]);
	}
	printf("In Alphabetical Order:\n");
	for(i=0; i<5; i++) {
		for(j=i+1; j<5; j++) {
			if(strcmp(str[i],str[j])>0) {
				strcpy(temp,str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],temp);
			}
		}
		puts(str[i]);
	}
}

