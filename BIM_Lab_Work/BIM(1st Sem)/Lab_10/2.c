// 2. WAP to add content in file "char.dat" and read and displays all the contents in console.

#include<stdio.h>
#include<stdlib.h>

void main(){
	FILE *fptr;
	char str[100],ch;
	fptr=fopen("char.dat","a+");
	if(fptr==NULL){
		printf("File opening error");
		exit(0);
	}
	printf("Enter some content to add: ");
	gets(str);
	// Add string to the file
	if(fputs(str,fptr)!=EOF){
		printf("Content added successfully\n");
	}
	else{
		printf("Error writing to file\n");
	}
	// Reset the file pointer
	rewind(fptr);
	// Read string from the file
	while((ch=fgetc(fptr))!=EOF){
		printf("%c",ch);
	}
	fclose(fptr);
}
