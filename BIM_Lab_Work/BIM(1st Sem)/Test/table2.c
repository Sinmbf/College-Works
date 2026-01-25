#include<stdio.h>
#include<windows.h>

struct employee{
	char name[20];
	int eid;
	int salary;
}emp[2];

void gotoxy(int x,int y){
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printHorizontalLine(int width);
void printRows(int,char *,int,int []);

void main(){
	int i=0;
	char ch;
	int width[]={4,20,6};
	int x=25,y;
	do{
		y=10;
		system("cls");
		gotoxy(x,y);
		printf("Enter details of employee:\n");
		gotoxy(x,++y);
		printf("Name: ");
		gets(emp[i].name);
		gotoxy(x,++y);
		printf("Employee Id: ");
		scanf("%d",&emp[i].eid);
		gotoxy(x,++y);
		printf("Salary: ");
		scanf("%d",&emp[i].salary);
		y+=2;
		gotoxy(x,y);
		printf("Do you want to add more?[y/n] ");
		scanf(" %c",&ch);
		fflush(stdin);
		printf("\n");
		i++;
	}while(ch=='y' || ch=='Y');
	y=10;
	system("cls");
	gotoxy(x,y);
	printHorizontalLine(width[0]+width[1]+width[2]+7);
	gotoxy(x,++y);
	printf("| EID | Name                | Salary|");
	gotoxy(x,++y);
	printHorizontalLine(width[0]+width[1]+width[2]+7);	
	for(i=0;i<3;i++){
		gotoxy(x,++y);
		printRows(emp[i].eid,emp[i].name,emp[i].salary,width);
		gotoxy(x,++y);
		printHorizontalLine(width[0]+width[1]+width[2]+7);
	}
}

void printHorizontalLine(int width){
	int i;
	for(i=0;i<width;i++){
		printf("-");
	}
	printf("\n");
}

void printRows(int eid,char *name,int salary,int width[]){
	printf("| %-*d| %-*s| %-*d|\n",width[0],eid,width[1],name,width[2],salary);
}
