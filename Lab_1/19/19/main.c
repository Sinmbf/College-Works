// WAP to read base and height of a triangle and calculate its area. [ area=1/2*b*h ]

#include<stdio.h>

int main(){
    int b,h;
    float area,area1;
    printf("Enter base: ");
    scanf("%d",&b);
    printf("Enter height: ");
    scanf("%d",&h);
    area=0.5*b*h;
    area1=(b*h)/2;
    printf("Area of the triangle = %g\nAlso = %g\b",area,area1);
    return 0;
}

