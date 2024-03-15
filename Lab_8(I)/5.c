// 5. WAP to display the sum and average of numbers from 1 to n.

#include<stdio.h>

void main(){
	int i,n,sum=0,*ptr;
	float avg;
	printf("Enter a number: ");
	scanf("%d",&n);
	ptr=&n;
	for(i=1;i<=*ptr;i++){
		sum+=i;
	}
	avg=(float)sum/(*ptr);
	printf("Sum = %d\nAverage=%.2f",sum,avg);
}
