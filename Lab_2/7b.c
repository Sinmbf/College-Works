// WAP that asks the user for three numbers. Then determine the smallest number among them

#include<stdio.h>

void main(){
	int n1,n2,n3;
	printf("Enter three numbers: ");
	scanf("%d%d%d",&n1,&n2,&n3);
	// Using nested if 
	if(n1<n2){
		if(n1<n3){
			printf("%d is the smallest\n",n1);
		}
		else{
			printf("%d is the smallest\n",n3);
		}
	}
	else if(n2<n3){
		printf("%d is the smallest\n",n2);
	}
	else{
		printf("%d is the smallest\n",n3);
	}
}
