// WAP to read two 2-D Array, multiply them and print the result

#include<stdio.h>

int main(){
	int a[20][20],b[20][20],c[20][20],i,j,k,r1,r2,c1,c2,res=0;
	printf("Enter the number of rows and columns in Matrix A: ");
	scanf("%d%d",&r1,&c1);
	printf("Enter the number of rows and columns in Matrix B: ");
	scanf("%d%d",&r2,&c2);
	if(c1!=r2){
		printf("Matrix multiplication not possible");
		return 0;
	}
	printf("Enter %d values for Matrix A: ",r1*c1);
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter %d values for Matrix B: ",r2*c2);
	for(i=0;i<r2;i++){
		for(j=0;j<c2;j++){
			scanf("%d",&b[i][j]);
		}
	}printf("Matrix C: (A*B)\n");
	
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			for(k=0;k<r2;k++){
				res+=a[i][k]*b[k][j];
			}
			c[i][j]=res;
			res=0;
			printf("%-4d",c[i][j]);
		}
		printf("\n");
	}
}
