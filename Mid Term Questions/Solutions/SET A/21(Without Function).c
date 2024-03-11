/*

21. WAP to implement a menu driven interface to allow the user to perform different operation.
The menu should include option to:

a. Calculate the factorial of a given number.
b. Check whether given number is Armstrong or not.
c. Check whether given number is odd/even.
d. Exit

Utilize loops to continuously display the menu and prompt the user for input until they choose
to exit

*/

#include<stdio.h>
#include<stdlib.h>

// Main Program
void main() {
	int n,opt,fact,rem,sum,org,i;
	do {
		printf("\n****MENU****\n");
		printf("\n1.Factorial\n2.Armstrong\n3.Odd Or Even\n4.Exit\n");
		printf("\n************\n");
		printf("Enter a number: ");
		scanf("%d",&n);
		printf("Which operation do you want to perform?[1-4]: ");
		scanf("%d",&opt);
		switch(opt) {
			case 1:
				fact=1;
				for(i=1; i<=n; i++) {
					fact*=i;
				}
				printf("Factorial of %d = %d\n",n,fact);
				break;
			case 2:
				org=n;
				sum=0;
				while(n!=0) {
					rem=n%10;
					sum=sum+(rem*rem*rem);
					n/=10;
				}
				if(org==sum) {
					printf("%d is Armstrong\n",org);
				} else {
					printf("%d is not Armstrong\n",org);
				}
				break;
			case 3:
				if(n%2==0) {
					printf("%d is Even\n",n);
				} else {
					printf("%d is Odd\n",n);
				}
				break;
			case 4:
				exit(1);
			default:
				printf("Invalid Option");
		}
	} while(opt!=4);
}

