#include<stdio.h>

void main(){
	int i,n1,n2,power=1;
	printf("Enter two numbers: ");
	scanf("%d%d",&n1,&n2);
	for(i=1;i<=n2;i++){
		power*=n1;
	}
	printf("%d power %d = %d\n",n1,n2,power);
}
