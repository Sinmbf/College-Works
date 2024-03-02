#include<stdio.h>
#include<string.h>
int main()
{
    char sen[20],temp[20];
    printf("Enter words:");
    gets(sen);
    strcpy(temp,sen);
    printf("copied successfully:\n%s",temp);
    return 0;
}
