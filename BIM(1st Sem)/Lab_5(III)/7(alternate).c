// 7. WAP to read 2-D Array. Add, subtract and print it using function. Also include 
// non-additional condition.

#include<stdio.h>
#include<stdlib.h>

// Function Prototype
void read(int,int,int a[10][10]);
void add(int,int,int a[10][10],int b[10][10]);
void subtract(int,int,int a[10][10],int b[10][10]);
void display(int,int,int c[10][10]);

// Main Program
void main(){
	int r1,r2,c1,c2,a[10][10],b[10][10],c[10][10],d[10][10],i,j,sum=0;
	printf("Enter the no. of rows and columns for matrix A: ");
	scanf("%d%d",&r1,&c1);
	printf("Enter the no. of rows and columns for matrix B: ");
	scanf("%d%d",&r2,&c2);
	if(r1!=r2 || c1!=c2){
		printf("Matrix addition not possible(Rows and columns not equal)");
		exit(0);
	}
	// Taking values for both matrix
	printf("Enter %d values for matrix A: ",r1*c1);
	read(r1,c1,a);
	printf("Enter %d values for matrix B: ",r2*c2);
	read(r1,c1,b);
	// Function call
	add(r1,c1,a,b);
	subtract(r1,c1,a,b);
}

// Function Definition (For reading values)
void read(int r1,int c1,int a[10][10]){
	int i,j;
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			scanf("%d",&a[i][j]);
		}
	}
}

// Function Definition (For adding matrix)
void add(int r1,int c1,int a[10][10],int b[10][10]){
	// Adding both matrix
	int i,j,c[10][10],d[10][10];
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			c[i][j]=a[i][j]+b[i][j]; // Add
		}
	}
	// Display
	printf("Sum:\n");
	display(r1,c1,c);	
}

// Function Definition (For subtracting matrix)
void subtract(int r1,int c1,int a[10][10],int b[10][10]){
	// Subtracting both matrix
	int i,j,c[10][10];
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			c[i][j]=a[i][j]-b[i][j]; // Subtract
		}
	}
	// Display
	printf("Difference:\n");
	display(r1,c1,c);	
}

// Function Definition (For displaying values)
void display(int r1,int c1,int c[10][10]){
	int i,j;
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			printf("%-4d",c[i][j]);
		}
		printf("\n");
	}
}
