#include<stdio.h>

void main(){
	int n,i,n1=0,n2=1,n3;
	printf("Enter the number of terms: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("%d\n",n1);
		n3=n1+n2;
		n1=n2;
		n2=n3;
	}
}
