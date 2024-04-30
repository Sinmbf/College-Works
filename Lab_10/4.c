// 4. WAP to read lines of text from the keyboard, write them to a file and then read them
// back again.

#include<stdio.h>
#include<stdlib.h>

void main(){
	FILE *fptr;
	char str[50];
	fptr=fopen("file4.txt","w+");
	if(fptr==NULL){
		printf("Error opening file4.txt");
		exit(1);
	}
	// Reading from the standard input(keyboard)
	printf("Enter a line of text: ");
	fgets(str,sizeof(str),stdin);
	// Writing into the file
	if(fputs(str,fptr)==EOF){
		printf("Error writing into file4.txt");
		exit(1);
	}
	// Reset file pointer
	rewind(fptr);
	// Read from the file
	while(fgets(str,sizeof(str),fptr)!=NULL){
		printf("%s",str);
	}
	fclose(fptr);
}
