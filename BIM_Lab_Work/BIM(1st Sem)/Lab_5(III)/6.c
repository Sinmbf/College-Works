// 6. WAP to read and display 2-D Array of size (mXn)

#include<stdio.h>

void read(int,int,int [20][20]);
void display(int,int,int [20][20]);

void main(){
	int a[20][20],m,n;
	printf("Enter the no. of rows: ");
	scanf("%d",&m);
	printf("Enter the no. of columns: ");
	scanf("%d",&n);
	read(m,n,a);
	display(m,n,a);
}

void read(int m,int n,int a[20][20]){
	int i,j;
	printf("Enter %d values: ",m*n);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
}

void display(int m,int n,int a[20][20]){
	int i,j;
	printf("Elements of the array:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d\n",a[i][j]);
		}
	}
}
