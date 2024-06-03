// WAP to take input 3*3 matrix and create a new matrix by replacing all the elements 
// of previous matrix by 15 if the element of previous matrix is less than 5

#include<stdio.h>

void main(){
	int a[3][3],b[3][3],i,j;
	printf("Enter 9 elements: ");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]<5){
				b[i][j]=15;
			}
			else{
				b[i][j]=a[i][j];
			}
		}
	}
	printf("New matrix with replaced values:\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%-4d",b[i][j]);
		}
		printf("\n");
	}
}
