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

// Function Prototypes
void factorial(int);
void armstrong(int);
void odd_even(int);

// Main Program
void main(){
	int n,opt;
	do{
		printf("\n****MENU****\n");
		printf("\n1.Factorial\n2.Armstrong\n3.Odd Or Even\n4.Exit\n");
		printf("\n************\n");
		printf("Enter a number: ");
		scanf("%d",&n);
		printf("Which operation do you want to perform?[1-4]: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				factorial(n);
				break;
			case 2:
				armstrong(n);
				break;
			case 3:
				odd_even(n);
				break;
			case 4:
				exit(1);
			default:
				printf("Invalid Option");
		}
	}while(opt!=4);
}

void factorial(int n){
	int fact=1,i;
	for(i=1;i<=n;i++){
		fact*=i;
	}
	printf("Factorial of %d = %d\n",n,fact);
}

void armstrong(int n){
	int rem,sum=0,org=n;
	while(n!=0){
		rem=n%10;
		sum=sum+(rem*rem*rem);
		n/=10;
	}
	if(org==sum){
		printf("%d is Armstrong\n",org);
	}
	else{
		printf("%d is not Armstrong\n",org);
	}
}

void odd_even(int n){
	if(n%2==0){
		printf("%d is Even\n",n);
	}
	else{
		printf("%d is Odd\n",n);
	}
}
