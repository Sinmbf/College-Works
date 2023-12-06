// WAP that read weight in gram and display how many kilogram and gram are there.

#include<stdio.h>

int main(){
    float g,kg;
    printf("Enter weight in gram: ");
    scanf("%f",&g);
    kg=g/1000;
    printf("%f weight in gram = %g kg\n",g,kg);
    return 0;
}
