// 9. WAP that displays the content of c:\\item.txt

#include<stdio.h>
#include<stdlib.h>

struct item{
	char name[20];
	int price; 
	int itm_code;
};

void main(){
	struct item itm;
	FILE *fptr;
	fptr=fopen("D:\\item.txt","rb");
	if(fptr==NULL){
		printf("Error opening item.txt");
		exit(1);
	}
	// Read from the file
	while(fread(&itm,sizeof(itm),1,fptr)){
		printf("Name: %s\nPrice: %d\nItem Code: %d\n",itm.name,itm.price,itm.itm_code);
	}
	fclose(fptr);
}
