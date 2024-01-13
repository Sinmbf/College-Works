#include<stdio.h>
//#include<conio.h>

void main(){
	char ch1,ch2;
	printf("Enter two characters: \n");
	// Getchar and Putchar
	/*
	ch1=getchar();
	ch2=getchar();
	printf("The two characters are: \n");
	putchar(ch1);
	printf("\t");
	putchar(ch2);
	printf("\n");
	*/
	// Getch, Getche and Putch
	printf("Enter a charcter: ");
	ch1=getch();
	printf("\n");
	printf("Enter another character: ");
	ch2=getche();
	printf("\n");
	printf("The two characters are: \n");
	putch(ch1);
	printf("\t");
	putch(ch2);
}
