// 1. WAP to write a character in a file named "char.dat" and also read the content and 
// display in console.

#include<stdio.h>
#include<stdlib.h>

void main(){
	FILE *fptr;
	char ch;
	fptr=fopen("char.dat","w+");
	if(fptr==NULL){
		printf("File opening error");
		exit(0);
	}
	printf("Enter a character: ");
	scanf("%c",&ch);
	// Write into file
	fputc(ch,fptr);
	// Reset the file pointer
	rewind(fptr);
	// Read from file and then display
	ch=fgetc(fptr);
	printf("%c",ch);
	fclose(fptr);
}
