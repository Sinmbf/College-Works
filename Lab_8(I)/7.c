// 7. WAP that can declare a 1-D array called height[20], accept its content using pointer
// and find the largest among them using pointer.

#include<stdio.h>

void main(){
	int height[20],*ptr,i,largest;
	ptr=height;
	printf("Enter 20 numbers: ");
	for(i=0;i<20;i++){
		scanf("%d",ptr+i);
	}
	largest=*ptr;
	for(i=1;i<20;i++){
		if(*(ptr+i)>largest){
			largest=*(ptr+i);
		}
	}
	printf("The largest element = %d",largest);
	
}
