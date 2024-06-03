#include<stdio.h>
#include<string.h>

int main(){
    char temp[10],a[10],b[10];
    printf("Enter a word: ");
    scanf("%s",a);
    printf("Enter a word: ");
    scanf("%s",b);
    printf("Before swapping:\na=%s\nb=%s\n",a,b);
    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);
    printf("After swapping:\na=%s\nb=%s\n",a,b);
    return 0;
    
}
