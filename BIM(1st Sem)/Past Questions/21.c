// 21. WAP to calculate simple interest and store the result in a file named "data.txt"

#include<stdio.h>
#include<stdlib.h>

int main() {
	int p,t,r;
	float SI;
	FILE *fptr;
	fptr=fopen("data.txt","w");
	if(fptr==NULL) {
		printf("Error opening data.txt");
		exit(1);
	}
	printf("Enter principal: ");
	scanf("%d",&p);
	printf("Enter rate: ");
	scanf("%d",&r);
	printf("Enter time ");
	scanf("%d",&t);
	SI=(float)(p*t*r)/100;
	printf("%.2f",SI);
	fprintf(fptr,"Simple Interest = %.2f",SI);
	fclose(fptr);
	return 0;
}
