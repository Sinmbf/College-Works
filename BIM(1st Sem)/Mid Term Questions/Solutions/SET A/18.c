// 18. WAP to check if two given matrices of size 3*3 are identical or not

#include<stdio.h>

void main(){
	int a[3][3],b[3][3],flag=1,i,j;
	printf("Enter 9 elements for matrix A: ");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter 9 elements for matrix B: ");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&b[i][j]);
		}
	}
	// Checking if they are identical
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(a[i][j]!=b[i][j]){
				flag=0;
				break;
			}
		}
		if(flag==0){
			break;
		}
	}
	if(flag==1){
		printf("They are identical");
	}
	else{
		printf("They are not identical");
	}
}
