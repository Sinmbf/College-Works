// 12. WAP that accepts 10 numbers and sort it in descending order.

#include<stdio.h>

void main(){
	int a[10],i,j,temp;
	printf("Enter 10 numbers: ");
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	// Arranging in descending order
	for(i=0;i<10-1;i++){
		for(j=i+1;j<10;j++){
			if(a[i]<a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	// Display
	printf("In Descending Order:\n");
	for(i=0;i<10;i++){
		printf("%d\n",a[i]);
	}
}
