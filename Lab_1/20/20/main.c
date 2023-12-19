// WAP to read three sides of a triangle and calculate the area. [ area=root under s(s-a)(s-b)(s-c) and s=(a+b+c)/2 ] where a, b and c are the sides of a triangle.

#include<stdio.h>
#include<math.h>

int main(){
    int a,b,c;
    float s,area;
    printf("Enter three sides of the triangle:\n");
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    s=(float)(a+b+c)/2;
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    printf("%g\n",s);
    printf("Area of the triangle = %g\n",area);
    return 0;
}
