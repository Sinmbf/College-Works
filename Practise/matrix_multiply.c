#include<stdio.h>

void main() {
	int a[3][4],b[4][3],c[3][3],i,j,k,res=0;
	printf("Enter 12 elements for matrix A:\n");
	for(i=0; i<3; i++) {
		for(j=0; j<4; j++) {
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter 12 elements for matrix B:\n");
	for(i=0; i<4; i++) {
		for(j=0; j<3; j++) {
			scanf("%d",&b[i][j]);
		}
	}
	printf("Matrix C: (A*B)\n");
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			for(k=0;k<4;k++){
				res+=a[i][k]*b[k][j];
			}
			c[i][j]=res;
			printf("%-4d",c[i][j]);
			res=0;
		}
		printf("\n");
	}
}
