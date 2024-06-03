// WAP to calculate volume of a box. Accept length, width and height from the user. [ volume=l*b*h ]

#include<stdio.h>

int main(){
    float l,b,h,volume;
    printf("Enter length: ");
    scanf("%f",&l);
    printf("Enter breadth: ");
    scanf("%f",&b);
    printf("Enter height: ");
    scanf("%f",&h);
    volume=l*b*h;
    printf("Volume of the box=%.2f\n",volume);
    return 0;
}ø
