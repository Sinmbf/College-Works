// Write two 3*4 matrix A and B and print them. And obtain matrix C=A-B
// and print
#include<stdio.h>

void main(){
	int a[3][4],b[3][4],c[3][4],i,j;
	printf("Enter 12 elements for matrix A:\n");
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter 12 elements for matrix B:\n");
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			scanf("%d",&b[i][j]);
		}
	}
	printf("Matrix A:\n");
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			printf("%-4d",a[i][j]);
		}
		printf("\n");
	}
	printf("\nMatrix B:\n");
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			printf("%-4d",b[i][j]);
		}
		printf("\n");
	}
	printf("\nMatrix C: (A-B)\n");
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			c[i][j]=a[i][j]-b[i][j];
			printf("%-4d",c[i][j]);
		}
		printf("\n");
	}
}
