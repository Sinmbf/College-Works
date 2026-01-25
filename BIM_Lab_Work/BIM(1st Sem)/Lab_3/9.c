#include<stdio.h>

void main(){
	int consumption;
	float total_bill;
	printf("Enter the consumption unit of electricity: ");
	scanf("%d",&consumption);
	if(consumption>=0 && consumption<=150){
		total_bill=3*consumption;
	}
	else if(consumption<=350){
		total_bill=(consumption-150)*3.75+(150*3);
	}
	else if(consumption<=450){
		total_bill=(consumption-350)*4+(350*3.75);
	}
	else{
		total_bill=(consumption-450)*4.25+(450*4);
	}
	printf("Total bill= %.2f",total_bill);
}
