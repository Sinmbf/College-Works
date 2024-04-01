// 3. WAP to copy content of one file to another file

#include<stdio.h>
#include<stdlib.h>

void main(){
	FILE *fptr1,*fptr2;
	char str[50];
	fptr1=fopen("file3.txt","w+");
	if(fptr1==NULL){
		printf("Error opening file3.txt");
		exit(1);
	}
	fptr2=fopen("copy3.txt","w");
	if(fptr1==NULL){
		printf("Error opening copy3.txt");
		exit(1);
	}
	printf("Enter some content to add: ");
	fgets(str,sizeof(str),stdin);
	// Write string to file
	if(fputs(str,fptr1)==EOF){
		printf("Error writing to file1.txt");
		exit(1);
	}
	// Reset the file pointer
	rewind(fptr1);
	// Read string from the file 1 and write it to another file(copy)
	while(fgets(str,sizeof(str),fptr1)!=NULL){
		if(fputs(str,fptr2)==EOF){
			printf("Error writing to file2.txt");
			exit(1);
		}
	}
	printf("Content successfully copied into another file");
	fclose(fptr1);
	fclose(fptr2);
}
