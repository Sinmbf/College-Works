#include<stdio.h>

void main(){
	int year;
	printf("List of leap years from 1900 to 2022: \n");
	for(year=1900;year<=2022;year++){	
		if(year%4==0 && year%100!=0){
			printf("%d\n",year);
		}
		else{
			if(year%4==0 && year%100==0 && year%400==0){
				printf("%d\n",year);
			}
		}
	}
}
