// 12. WAP that generates bill for the items purchased by the user.

#include<stdio.h>
#include<stdlib.h>

struct item {
	char name[20];
	int price;
	int itm_code;
};

void main() {
	struct item itm;
	FILE *fptr;
	int code,bill=0,count=0;
	char choice;
	fptr=fopen("D:\\item.txt","rb");
	if(fptr==NULL) {
		printf("Error opening item.txt");
		exit(1);
	}
	printf("Item Code Name           Price\n");
	// Reading from the file
	while(fread(&itm,sizeof(itm),1,fptr)) {
		printf("%-10d%-15s%d\n",itm.itm_code,itm.name,itm.price);
	}
	rewind(fptr);
	do {
		printf("Enter the item code of the item you want to purchase: ");
		scanf("%d",&code);
		while(fread(&itm,sizeof(itm),1,fptr)) {
			if(itm.itm_code==code){
				bill+=itm.price;
				count++;
				break;
			}
		}
		printf("Do you want to purchase more?[y/n] ");
		scanf(" %c",&choice);
	} while(choice=='y' || choice=='Y');
	printf("You purchased %d items. Your total bill is %d",count,bill);
	fclose(fptr);
}
