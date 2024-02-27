// WAP to read two arrays, add two arrays and store the result in third array and display
// the array. Define read() to read data, sum() to add the array elements and display() to 
// display the final result.

#include<stdio.h>

// Function Prototype
int read();
int sum(int,int);
void display();

// Main Function
void main(){
	int a[5],b[5],c[5],i;
	printf("Enter 5 elements for first array: ");
	for(i=0;i<5;i++){
		a[i]=read();
	}
	printf("Enter 5 elements for second array: ");
	for(i=0;i<5;i++){
		b[i]=read();
	}
	for(i=0;i<5;i++){
		c[i]=sum(a[i],b[i]);
	}
	printf("The sum of the two arrays:\n");
	for(i=0;i<5;i++){
		display(c[i]);
	}
	
}

// Function Definition
int read(){
	int n;
	scanf("%d",&n);
	return n;
}

int sum(n1,n2){
	return n1+n2;
}

void display(sum){
	printf("%d\n",sum);
}
