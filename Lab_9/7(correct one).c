// WAP to store average rainfall of the first half of year and then display them in the given 
// format.

/*
	
	i) Create a user defined structure that can store the above data
	ii) Display the data exactly the same format as given
*/
#include<stdio.h>

// 5 City ==> 5 Rainfall
struct city{
	int r[6];
}c[5];

int main(){
	int i,j;
	char mnth[6][10]={"January","February","March","April","May","June"};  
	char cty[5][10]={"Kathmandu","New Delhi","Bankok","Tokyo","Colombo"};
	printf("Enter average rainfall:\n");
	for(i=0;i<5;i++){
		printf("\nFor %s:\n",cty[i]);
		for(j=0;j<6;j++){
			printf("In %s: ",mnth[j]);
			scanf("%d",&c[i].r[j]);
		}
	}
	printf("\nRainfall of the first half of year\n");
	printf("\nCity Name  Jan  Feb  Mar  Apr  May  June\n");
	for(i=0;i<5;i++){
		printf("%-12s",cty[i]);
		for(j=0;j<6;j++){
			printf("%-5d",c[i].r[j]);
		}
		printf("\n");
	}
	return 0;
}
