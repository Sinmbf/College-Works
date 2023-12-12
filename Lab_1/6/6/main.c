// WAP that accepts three number from the user and display the average

#include<stdio.h>

int main(){
    float n1,n2,n3;
    float avg;
    printf("Enter the first number: ");
    scanf("%f",&n1);
    printf("Enter the second number: ");
    scanf("%f",&n2);
    printf("Enter the third number: ");
    scanf("%f",&n3);
    avg=(n1+n2+n3)/3;
    printf("Average of %g, %g and %g is %.2f\n",n1,n2,n3,avg);
    return 0;
}
