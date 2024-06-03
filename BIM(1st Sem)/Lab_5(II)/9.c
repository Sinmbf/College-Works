// WAP to take two 1-D array of size n and m and merge them into a single array
// with size n+m. And display them.

#include<stdio.h>

void main(){
	int a[100],b[100],c[100],i,n,m,j,count=0;
	printf("Enter the size of first array: ");
	scanf("%d",&n);
	printf("Enter %d values: ",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter the size of second array: ");
	scanf("%d",&m);
	printf("Enter %d values: ",m);
	for(i=0;i<m;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<n+m;i++){
		if(i<n){
			c[i]=a[i];
		}
		else{
			c[i]=b[count];
			count++;
		}
	}
	printf("Merged array of size %d:\n",n+m);
	for(i=0;i<n+m;i++){
		printf("%-4d",c[i]);
	}
		
}
