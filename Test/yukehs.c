//Write a program that accept information of 10 items and write it to file called c:\\item.txt.
//Use structure for information.
#include<stdio.h>
#include<stdlib.h>
struct item
{
	char name[20];
	int price;
	float quantity;
}itm[10];
void main()
{
	FILE *fp;
	int i;
	fp=fopen("c:\item.txt","w");
	if(fp==NULL)
	{
		printf("Error on opening file");
		exit(0);
	}
	printf("Enter any 10 item information\n");
	for(i=0;i<2;i++)
	{
		printf("\nEnter the name of item:");
		fflush(stdin);
		gets(itm[i].name);
		printf("Enter the price of the item:");
		scanf("%d",&itm[i].price);
		printf("Enter the quantity age:");
		scanf("%f",&itm[i].quantity);
	}
	
	for(i=0;i<2;i++)
	{
		fwrite(&itm,sizeof(itm),1,fp);
	}
	fclose(fp);
}
