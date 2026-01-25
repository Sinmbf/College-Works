#include<stdio.h>

void main(){
	int n1=0,n2=1,n3,i;
	for(i=0;i<5;i++){
		printf("%d\n",n1);
		n3=n1+n2;
		n1=n2;
		n2=n3;
	}
}
