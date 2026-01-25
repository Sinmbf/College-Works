#include<stdio.h>
#include<stdlib.h>
struct library {
	float price;
	char book_name[100];
	char author[100];
	int page;
};
void add();
void display();
void total();
void main() {
	int num;
	printf("********Welcome to the Library********\n");
	printf("1.Add Book Details\n");
	printf("2.Display the list of books and its details\n");
	printf("3.Display the total no. of books in the library\n");
	printf("4.Exit\n");
	printf("Please Enter Your Choice:");
	scanf("%d",&num);
	switch(num) {
		case 1:
			add();
			break;

		case 2:
			//	display();
			break;

		case 3:
			//	total();
			break;

		case 4:
			exit(0);
			break;

		default:
			printf("Invalid number");

	}
}

void add() {
	FILE *fp;
	struct library *l1;
	char ch;
	l1=(struct library *)malloc(sizeof(struct library));
	if(l1==NULL) {
		printf("Memory not allocated");
		exit(0);
	}
	fp=fopen("library.txt","a");
	if(fp==NULL) {
		printf("Enter on opening file");
		exit(0);
	}
	system("cls");
	do {
		printf("Add details of book");
		printf("Enter the name of book:");
		gets(l1->book_name);
		printf("Enter the name of the author:");
		gets(l1->author);
		fflush(stdin);
		printf("Enter the price of book:");
		scanf("%f",&l1->price);
		printf("Enter the number of pages:");
		scanf("%d",&l1->page);
		fwrite(l1,sizeof(struct library),1,fp);
		printf("Do You want to add more details of book (y/n):");
		scanf("c",&ch);
	} while(ch=='Y'||ch=='y');
	fclose(fp);
	free(l1);
}
