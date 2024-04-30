// 12. Create a union name with members firstname, middlename, and lastname. WAP that 
// inputs values and store in members. Also display the values of members.

#include<stdio.h>

union name{
	char firstName[20];
	char middleName[20];
	char lastName[20];
};

void main(){
	union name n;
	printf("Enter first name: ");
	gets(n.firstName);
	printf("Enter middle name: ");
	gets(n.middleName);
	printf("Enter last name: ");
	gets(n.lastName);
	// The values in a union gets replaced or overwritten by the latest value
	// Since all the members share the same space and can't be active at the same time
	printf("\nFirst Name: %s\nMiddle Name: %s\nLast Name: %s\n",n.firstName,n.middleName,n.lastName);
}
