/* 

22. WAP to implement a menu-driven interface to allow the user to perform different operations:
The menu should include options to:

	a. Read a number and find its square root.
	b. Read three numbers and find the greatest.
	c. Read two numbers as a and b and calculates c=ab.
	d. Exit.

Utilize loops to continuously display the menu and prompt the user for input until they choose
to exit.

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main(){
	int a,b,c,opt;
	float res;
	do{
		printf("\n****MENU****\n");
		printf("\n1. Find the square root of a given number\n");
		printf("2. Read three numbers and find the greatest\n");
		printf("3. Read two numbers and find their product\n");
		printf("4. Exit\n");
		printf("\n************\n");
		printf("Which operation do you want to perform?[1-4]: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Enter a number: ");
				scanf("%d",&a);
				printf("Square root of %d = %.2f\n",a,sqrt(a));
				break;
			case 2:
				printf("Enter three numbers: ");
				scanf("%d%d%d",&a,&b,&c);
				if(a>b && a>c){
					printf("%d is the greatest\n",a);
				}
				else if(b>a && b>c){
					printf("%d is the greatest\n",b);
				}
				else{
					printf("%d is the greatest\n",c);
				}
				break;
			case 3:
				printf("Enter two numbers: ");
				scanf("%d%d",&a,&b);
				c=a*b;
				printf("Product = %d\n",c);
				break;
			case 4:
				exit(1);
			default:
				printf("Invalid Option\n");
		}
	}while(opt!=4);
}
