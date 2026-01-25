#include<stdio.h>

void main(){
	int i,j,k,n,count=0;
//	for(i=5;i>=1;i--){
////		count++;
////		n=i+count;
//		for(k=1;k<6-i;k++){
//			printf(" ");
//		}
//		for(j=1;j<=i;j++){
//			printf("%d",i);
//		}
//		printf("\n");
//	}
	for(i='E';i>='A';i--){
		for(k='E';k>i;k--){
			printf(" ");
		}
		for(j='A';j<=i;j++){
			printf("%c",i);
		}
		printf("\n");
	}
}
