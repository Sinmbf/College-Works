// 8. WAP to read two matrices, multiply them and store it in 3rd array and display them.
// Also include non-multiplication condition.

#include<stdio.h>
#include<stdlib.h>

// Function Prototype
void read(int,int,int [10][10]);
void multiply(int,int,int,int,int a[10][10],int b[10][10]);
void display(int,int,int c[10][10]);

void main() {
	int r1,r2,c1,c2,res=0,a[10][10],b[10][10];
	printf("Enter the no. of rows and columns for matrix A: ");
	scanf("%d%d",&r1,&c1);
	printf("Enter the no. of rows and columns for matrix B: ");
	scanf("%d%d",&r2,&c2);
	if(c1!=r2) {
		printf("Matrix multiplication not possible!");
	} else {

		printf("Enter %d values for matrix A: ",r1*c1);
		read(r1,c1,a);
		printf("Enter %d values for matrix B: ",r2*c2);
		read(r2,c2,b);
		multiply(r1,c1,r2,c2,a,b);
	}
}

void read(int r,int c,int a[10][10]) {
	int i,j;
	for(i=0; i<r; i++) {
		for(j=0; j<c; j++) {
			scanf("%d",&a[i][j]);
		}
	}
}

void multiply(int r1,int c1,int r2,int c2,int a[10][10],int b[10][10]) {
	int i,j,k,res=0,c[10][10];
	for(i=0; i<r1; i++) {
		for(j=0; j<c2; j++) {
			res=0;
			for(k=0; k<r2; k++) {
				res+=a[i][k]*b[k][j];
			}
			c[i][j]=res;
		}
	}
	display(r1,c2,c);
}

void display(int r,int c,int m[10][10]) {
	printf("Matrix Multiplication:\n");
	int i,j;
	for(i=0; i<r; i++) {
		for(j=0; j<c; j++) {
			printf("%-4d",m[i][j]);
		}
		printf("\n");
	}

}

