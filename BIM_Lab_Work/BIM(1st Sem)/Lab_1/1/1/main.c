// WAP that can calculate area and circumference of the circle [ A= pi*r*r and C=2*pi*r ]

#include<stdio.h>

int main(){
    float r,area,circumference,pi=3.14;
    printf("Enter radius: ");
    scanf("%f",&r);
    area=pi*r*r;
    circumference=2*pi*r;
    printf("Area of the circle=%.2f\n",area);
    printf("Circumference of the circle=%.2f\n",circumference);
    return 0;
}
