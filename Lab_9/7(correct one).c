// WAP to store average rainfall of the first half of year and then display them in the given 
// format.

#include<stdio.h>

// 5 City ==> 5 Rainfall
struct city{
	int r[5];
}c[5];

int main(){
	int i,j;
	char mnth[5][10]={"January","February","March","April","May"};  
	char cty[5][10]={"Kathmandu","New Delhi","Bankok","Tokyo","Colombo"};
	printf("Enter average rainfall:\n\n");
	for(i=0;i<5;i++){
		printf("For %s:\n",cty[i]);
		for(j=0;j<5;j++){
			printf("In %s: ",mnth[j]);
			scanf("%d",&c[i].r[j]);
		}
		printf("\n");
	}
	printf("\nRainfall of the first half of year\n");
	printf("\nCity Name  Jan  Feb  Mar  Apr  May\n");
	for(i=0;i<5;i++){
		printf("%-12s",cty[i]);
		for(j=0;j<5;j++){
			printf("%-5d",c[i].r[j]);
		}
		printf("\n");
	}
	return 0;
}
