// 8. WAP that accept information of 10 items and write it to file called c:\\item.txt
// Use structure for information.

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
	fptr=fopen("D:\\item.txt","wb");
	if(fptr==NULL){
		printf("Error opening item.txt");
		exit(1);
	}
	for(i=0;i<10;i++){
		// Reading from standard input(keyboard)
		printf("Enter details of item %d:\n",i+1);
		printf("Name: ");
		gets(itm.name);
		printf("Price: ");
		scanf("%d",&itm.price);
		printf("Item code: ");
		scanf("%d",&itm.itm_code);
		fflush(stdin);
		// Writing into file
		fwrite(&itm,sizeof(itm),1,fptr);
	}
	printf("Successfully written into file item.txt");
	fclose(fptr);
}
