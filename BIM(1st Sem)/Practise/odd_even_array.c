#include<stdio.h>

void main(){
	int a[5],e[5],o[5],i,count1=0,count2=0;
	printf("Enter 5 elements: ");
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
		if(a[i]%2==0){
			e[count1]=a[i];
			count1++;
		}
		else{
			o[count2]=a[i];
			count2++;
		}
	}
	printf("Even elements:\n");
	for(i=0;i<count1;i++){
		printf("%d\n",e[i]);
	}
	printf("Odd elements:\n");
	for(i=0;i<count2;i++){
		printf("%d\n",o[i]);
	}
}
