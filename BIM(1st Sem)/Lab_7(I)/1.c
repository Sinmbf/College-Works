#include<stdio.h>
#include<conio.h>
void main() {
	int x=9;
	int *xptr=&x;
	int **xpptr=&xptr;
	printf("Content of x:%d\n",x); // 9
	printf("Content of x:%d\n",*xptr);  // 9
	printf("Content of x:%d\n",*(*(xpptr))); // 9 
	printf("Address of x:%d\n",&x); // address of x
	printf("Address of x:%d\n",xptr); // address of x
	printf("Address of x:%d\n",*xpptr);   // address of x
	printf("Content of xptr:%d\n",xptr);  // address of x
	printf("Content of xptr:%d\n",*xpptr);// address of x
	printf("Address of xptr:%d\n",&xptr); // address of xptr
	printf("Address of xptr:%d\n",xpptr); // address of xptr
	getch();
}
