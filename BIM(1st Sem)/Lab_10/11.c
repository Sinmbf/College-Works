// 11. WAP that accept item code of an item, search the file c:\\item.txt and display the
// information of that item.

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
	int code,flag=0;
	fptr=fopen("D:\\item.txt","rb");
	if(fptr==NULL){
		printf("Error opening item.txt");
		exit(1);
	}
	// Reading from standard input(keyboard)
	printf("Enter item code: ");
	scanf("%d",&code);
	// Reading from the file
	while(fread(&itm,sizeof(itm),1,fptr)){
		if(itm.itm_code==code){
			printf("Name: %s\nPrice: %d",itm.name,itm.price);
			flag=1;
			break;
		}
	}
	if(flag==0){
		printf("No item found");
	}
	fclose(fptr);
}
