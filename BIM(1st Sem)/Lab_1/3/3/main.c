// WAP that accepts two numbers and display their addition,subtraction

#include<stdio.h>

int main(){
    int n1,n2,sum,difference,rem;
    float quotient;
    printf("Enter first number: ");
    scanf("%d",&n1);
    printf("Enter second number: ");
    scanf("%d",&n2);
    sum=n1+n2;
    difference=n1-n2;
    quotient=(float)n1/n2; // Casting integer to float
    rem=n1%n2;
    printf("Sum=%d\nDifference=%d\nQuotient=%g\nRemainder=%d\n",sum,difference,quotient,rem);
    return 0;
}
