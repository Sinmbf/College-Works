#include<stdio.h>

void main(){
	int i,j,a[5],temp;
	printf("Enter 5 elements: ");
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
	}
	printf("In Ascending Order:\n");
	for(i=0;i<5;i++){
		for(j=i+1;j<=5-1;j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		printf("%d\n",a[i]);
	}
	printf("In Descending Order:\n");
	for(i=0;i<5;i++){
		for(j=i+1;j<=5-1;j++){
			if(a[i]<a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		printf("%d\n",a[i]);
	}
}
