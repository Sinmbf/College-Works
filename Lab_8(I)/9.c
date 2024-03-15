// 9. WAP that can declare a 1-D array of size n. Now accept the content of that array
// and display their content.

#include<stdio.h>
#include<stdlib.h>

void main(){
	int *ptr,i,n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	ptr=(int *)malloc(n*sizeof(int));
	printf("Enter %d values: ",n);
	for(i=0;i<n;i++){
		scanf("%d",ptr+i);
	}
	printf("Content of the array:\n");
	for(i=0;i<n;i++){
		printf("%d\n",*(ptr+i));
	}
}
