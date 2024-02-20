//display only prime
#include<stdio.h>
void main() {
	int a[100],i,j,n,flag=1;
	printf("Enter no. of integers : ");
	scanf("%d",&n);
	printf("Enter %d integers : ",n);
	for(i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	printf("Prime Numbers :\n");
	for(i=0; i<n; i++) {
		flag=1;
		if((a[i]%2==0 && a[i]>2) || a[i]<=1) {
			continue;
		}
		for(j=3; j<=a[i]/2; j+=2) {
			if(a[i]%j==0) {
				flag=0;
				break;
			}
		}
		if(flag) printf("%-6d",a[i]);
	}
}
