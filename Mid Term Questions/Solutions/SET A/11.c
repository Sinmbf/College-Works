// 11. WAP to reverse a string without using any function

#include<stdio.h>

void main(){
	char str[100],temp;
	int i,len=0;
	printf("Enter a line: ");
	gets(str);
	for(i=0;str[i]!='\0';i++){
		len++;
	}
	i=0;
	len=len-1;
	while(i<len){
		temp=str[i];
		str[i]=str[len];
		str[len]=temp;
		i++;
		len--;
	}
	printf("Reverse String:\n%s",str);
}
