//b power p using function
#include<stdio.h>
float power(float,int);
void main() {
	float b,r;
	int p;
	printf("Enter base & power : ");
	scanf("%f%d",&b,&p);
	r=power(b,p);
	printf("%g to the power %d = %g",b,p,r);
}
float power(float b,int p) {
	int i;
	float s=1;
	if(p>=0) {
		for(i=1; i<=p; i++)
			s*=b;
	} else {
		for(i=1; i<=(-p); i++)
			s=s*(1/b);
	}
	return(s);
}
