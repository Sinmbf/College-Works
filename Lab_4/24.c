#include<stdio.h>

void main(){
	int sqr,i;
	for(i=1;i<=100;i++){
		if(i%11==0){
			continue;
		}
		sqr=i*i;
		printf("%d\n",sqr);
	}
}
