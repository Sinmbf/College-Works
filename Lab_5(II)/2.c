// WAP to take input 3*3 matrix and display the sum of each element of matrix
#include<stdio.h>

void main(){
	int i,j,sum=0,a[3][3];
	printf("Enter 9 elements: ");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&a[i][j]);
			sum+=a[i][j];
		}
	}	
	printf("The sum of each element of matrix is %d",sum);
}
