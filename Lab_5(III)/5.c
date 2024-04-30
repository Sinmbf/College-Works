#include<stdio.h>

void read(int, int []);
void sec_lowest(int,int []);

void main(){
	int n,a[100];
	printf("How many persons? ");
	scanf("%d",&n);
	read(n,a);
	sec_lowest(n,a);
}

void read(int n,int a[100]){
	int i;
	printf("Enter age of %d students: ",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}

void sec_lowest(int n,int a[100]){
	int lowest=a[0],i,sec_lowest=a[1];
	for(i=0;i<n;i++){
		if(a[i]<lowest){
			sec_lowest=lowest;
			lowest=a[i];
		}
	}
	for(i=0;i<n;i++){
		if(a[i]!=lowest && a[i]<sec_lowest){
			sec_lowest=a[i];
		}
	}
	printf("Second lowest age = %d",sec_lowest);
	
	
}
