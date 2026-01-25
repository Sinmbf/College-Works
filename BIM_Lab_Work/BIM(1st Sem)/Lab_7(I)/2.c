// WAP that calls a function getArea(). This function is responsible for reading the length
// and breadth and print the area

// No argument no return type

#include<stdio.h>

void getArea();

void main(){
	getArea();
}

void getArea(){
	int l,b,area;
	printf("Enter length: ");
	scanf("%d",&l);
	printf("Enter breadth: ");
	scanf("%d",&b);
	printf("The area of the rectangle is %d",l*b);
}
