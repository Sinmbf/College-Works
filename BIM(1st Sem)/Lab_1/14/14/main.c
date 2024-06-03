// WAP to convert temperature in centigrade into fahrenheit [ F = (C*1.8)+32 and C = (F-32)/1.8) ]

#include<stdio.h>

int main(){
    int C;
    float F;
    printf("Enter temperature in centigrade: ");
    scanf("%d",&C);
    F=(C*1.8)+32;
    printf("%d degree centigrade into fahrenheit = %g\n",C,F);
    return 0;
}

