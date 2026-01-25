// WAP to read an array and sort them in ascending and descending order

#include<stdio.h>

// Function Prototype
void read();
void display(int []);
void ascending(int []);
void descending(int []);

// Main Function
void main() {
	int a[5];
	read(a);
	ascending(a);
	display(a);
	descending(a);
	display(a);
}

void read(int a[5]) {
	int i;
	printf("Enter 5 numbers: ");
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
	}
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

void display(int a[5]){
	int i;
	for(i=0;i<5;i++){
		printf("%d\n",a[i]);
	}
}
