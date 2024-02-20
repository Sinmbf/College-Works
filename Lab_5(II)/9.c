// WAP to take two 1-D array of size n and m and merge them into a single array
// with size n+m. And display them.

#include<stdio.h>

void main(){
	int a[100],b[100],c[100],i,n,m,j,k,size;
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
	size=n+m;
	k=n;
	for(i=0;i<n;i++){
		c[i]=a[i];
		for(j=0;j<m;j++){
			c[k]=b[j];
			k++;
		}
	}
	printf("Merged array of size %d:\n",size);
	for(i=0;i<size;i++){
		printf("%-4d",c[i]);
	}
		
}
