#include<stdio.h>

void main(){
	int i,age,count=0;
	for(i=1;i<=10;i++){
		printf("Enter age of person %d: ",i);
		scanf("%d",&age);
		if(age>=50 && age<=60){
			count++;
		}
	}
	printf("The number of person of age group 50-60 = %d",count);
}
