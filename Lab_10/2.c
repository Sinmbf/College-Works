// 2. WAP to add content in file "char.dat" and read and displays all the contents in console.

#include<stdio.h>
#include<stdlib.h>

void main(){
	FILE *fptr;
	char str[100];
	fptr=fopen("char.dat","a+");
	if(fptr==NULL){
		printf("File opening error");
		exit(0);
	}
	printf("Enter some content to add: ");
	gets(str);
	// Add string to the file
	fputs(str,fptr);
	// Reset the file pointer
	rewind(fptr);
	// Read string from the file
	while(fgets(str,sizeof(str),fptr)!=NULL){
		printf("%s",str);
	}
	fclose(fptr);
}
