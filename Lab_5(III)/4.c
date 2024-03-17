// WAP to read an array and sort them in ascending and descending order

#include<stdio.h>

// Function Prototype
int read();
void ascending(int []);
void descending(int []);

// Main Function
void main() {
	int i,j,a[5],temp;
	printf("Enter 5 numbers: ");
	for(i=0; i<5; i++) {
		a[i]=read();
	}
	ascending(a);
	for(i=0;i<5;i++){
		printf("%d\n",a[i]);
	}
	descending(a);
	for(i=0;i<5;i++){
		printf("%d\n",a[i]);
	}
}

int read() {
	int n;
	scanf("%d",&n);
	return n;
}

void ascending(int a[5]) {
	int i,j,temp;
	printf("\nIn Ascending Order:\n");
	for(i=0;i<5-1;i++){
		for(j=i+1;j<5;j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

void descending(int a[5]) {
	int i,j,temp;
	printf("\nIn Descending Order:\n");
	for(i=0;i<5-1;i++){
		for(j=i+1;j<5;j++){
			if(a[i]<a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
