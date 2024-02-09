#include<stdio.h>

void main(){
	int count=0,sum=0,i;
	for(i=101;i<200;i++){
		if(i%7==0 && i%5!=0){
			count++;
			sum+=i;
		}
	}
	printf("The sum of all from 101-199 that are exactly divisible by 7 but not by 5:\n%d\nTotal numbers = %d\n",sum,count);
}
