// 9. Write a structure to store the name, account number and balance of customers(more than 10)
// and store their information.

/*

	a.) Write a function to print the names of all the customers having balance<200
	b.) Write a function to add 100 in the balance of all customers having more than
	1000 in their balance and then print the incremented value of their balance.

*/

#include<stdio.h>

struct customer {
	char name[20];
	int accNo;
	int balance;
};

void display(struct customer c[]);
void updateBalance(struct customer c[]);

void main() {
	struct customer c[11];
	int i;
	for(i=0; i<11; i++) {
		fflush(stdin);
		printf("Details of customer %d:\n",i+1);
		printf("Name: ");
		gets(c[i].name);
		printf("Account Number: ");
		scanf("%d",&c[i].accNo);
		printf("Balance: ");
		scanf("%d",&c[i].balance);
	}
	display(c);
	updateBalance(c);
}

// Function to display customers with balance < 200
void display(struct customer c[]) {
	int i;
	printf("\nCustomers with balance less than 200:\n");
	printf("Acc No Name                Balance\n");
	for(i=0; i<11; i++) {
		if(c[i].balance<200) {
			printf("%-7d%-20s%d\n",c[i].accNo,c[i].name,c[i].balance);
		}
	}
}

// Function to update balance
void updateBalance(struct customer c[]) {
	int i;
	printf("\nCustomers with balance > 1000 (100 bonus):\n");
	printf("Acc No Name                Balance\n");
	// Increment balance and display
	for(i=0; i<11; i++) {
		if(c[i].balance>1000) {
			c[i].balance+=100;
			printf("%-7d%-20s%d\n",c[i].accNo,c[i].name,c[i].balance);
		}
	}
}
