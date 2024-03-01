#include<stdio.h>

void main(){
	char a[100],org[100],temp;
	int i,len=0,pal=0;
	printf("Enter a word: ");
	gets(a);
	for(i=0;a[i]!='\0';i++){
		org[i]=a[i];
		len++;
	}
	len--;
	i=0;
	while(i<len){
		temp=a[i];
		a[i]=a[len];
		a[len]=temp;
		len--;
		i++;
	}
	for(i=0;a[i]!='\0';i++){
		if(org[i]!=a[i]){
			pal=1;
			break;
		}
	}
	if(pal==1){
		printf("Not a palindrome");
	}
	else{
		printf("Palindrome");
	}
}
