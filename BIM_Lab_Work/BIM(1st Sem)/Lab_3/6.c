#include<stdio.h>

void main(){
	int y1,y2,y3,m1,m2,m3,d1,d2,d3;
	printf("Enter the current date in [YY-MM-DD] format: ");
	scanf("%d-%d-%d",&y1,&m1,&d1);
	printf("Enter your date of birth in [YY-MM-DD] format: ");
	scanf("%d-%d-%d",&y2,&m2,&d2);
	y3=y1-y2;
	m3=m1-m2;
	d3=d1-d2;
	if(d3<0){
		m3--;
		d3=d3+30;
	}
	if(m3<0){
		y3--;
		m3=m3+12;
	}
	printf("Your age is %d years, %d months and %d days\n",y3,m3,d3);
}
