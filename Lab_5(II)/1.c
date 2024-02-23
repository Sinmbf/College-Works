// WAP to take input 3*3 matrix and display it
#include<stdio.h>

void main(){
	int a[3][3],i,j;
	printf("Enter 9 values: ");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("The elements in the array:\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%-4d ",a[i][j]);
		}
		printf("\n");
	}
}
