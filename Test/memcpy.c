#include<stdio.h>
#include<string.h>

void main(){
	char src[50]="Nepal";
	char dest[50]="Helloooo!!";
	strcpy(dest,src);
	printf("Before memcpy dest = %s\n",dest);
	memcpy(dest,src,strlen(src)+1);
	printf("After memcpy dest = %s\n",dest);
}
