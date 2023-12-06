// WAP to read base and height of a triangle and calculate its area. [ area=1/2*b*h ]

#include<stdio.h>

int main(){
    int b,h;
    float area;
    printf("Enter base: ");
    scanf("%d",&b);
    printf("Enter height: ");
    scanf("%d",&h);
    area=(b*h)/2;
    printf("Area of the triangle = %g\n",area);
    return 0;
}

