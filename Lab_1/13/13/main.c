#include<stdio.h>
#include<math.h>

int main(){
    int num;
    float degree,sine,cosine,tangent;
    printf("Enter a number: ");
    scanf("%d",&num);
    degree=num*(3.14/180);
    sine=sin(degree);
    cosine=cos(degree);
    tangent=tan(degree);
    printf("Sin%d = %g\nCos%d = %g\nTan%d = %g\n",num,sine,num,cosine,num,tangent);
    return 0;
}
    
