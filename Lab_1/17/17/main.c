// WAP to convert rupees into dollars

#include<stdio.h>

int main(){
    float rupees,dollars;
    printf("Enter nepalese rupees: ");
    scanf("%f",&rupees);
    dollars=rupees/133.39;
    printf("%f rupees into dollars = %g\n",rupees,dollars);
    return 0;
}
