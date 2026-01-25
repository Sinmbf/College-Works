// 17. WAP to calculate XA + YB where A and B are 2*2 matrices and X=2 and Y=3

#include<stdio.h>

void main(){
	int a[2][2],b[2][2],res1,res2,res3[2][2],x=2,y=3,i,j;
	printf("Enter 4 elements for matrix A: ");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter 4 elements for matrix B: ");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			scanf("%d",&b[i][j]);
		}
	}
	// Calculate XA + XB
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			res1=x*a[i][j];
			res2=y*b[i][j];
			res3[i][j]=res1+res2;
		}
	}
	// Display
	printf("Result:(XA + XB)\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%-4d",res3[i][j]);
		}
		printf("\n");
	}
}
