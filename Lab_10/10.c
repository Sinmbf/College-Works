// 10. WAP thad adds information of 5 more items to c:\\item.txt.

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
	int i;
	fptr=fopen("D:\\item.txt","ab");
	if(fptr==NULL){
		printf("Error opening item.txt");
		exit(1);
	}
	// Read from standard input(Keyboard)
	for(i=0;i<5;i++){
		printf("Enter details of item %d:\n",i+1);
		printf("Name: ");
		gets(itm.name);
		printf("Price: ");
		scanf("%d",&itm.price);
		printf("Item code: ");
		scanf("%d",&itm.itm_code);
		fflush(stdin);
		// Appeding into file
		fwrite(&itm,sizeof(itm),1,fptr);
	}
	printf("5 more items successfully added to item.txt");
	fclose(fptr);
}
