#include<stdio.h>

void display(int);

void main(){
	display(5);
}

void display(int n){
	if(n==0){
		return;
	}
	printf("Hello World\n");
	display(n-1);
	
}
