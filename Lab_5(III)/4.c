// WAP to read an array and sort them in ascending and descending order

#include<stdio.h>

// Function Prototype
int read();
int ascending(int a[],int);
int descending(int a[],int);

// Main Function
void main() {
	int i,j,a[5],temp;
	printf("Enter 5 numbers: ");
	for(i=0; i<5; i++) {
		a[i]=read();
	}
	ascending(a,5);
	descending(a,5);
}

int read() {
	int n;
	scanf("%d",&n);
	return n;
}

int ascending(int a[5],int size) {
	int i,j,temp;
	printf("\nIn Ascending Order:\n");
	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		printf("%d\n",a[i]);
	}
}

int descending(int a[5],int size) {
	int i,j,temp;
	printf("\nIn Descending Order:\n");
	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			if(a[i]<a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		printf("%d\n",a[i]);
	}
}
