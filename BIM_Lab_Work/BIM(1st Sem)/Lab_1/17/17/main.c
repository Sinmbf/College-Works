// WAP to convert rupees into dollars

#include<stdio.h>

int main(){
    int rupees;
    float dollars;
    printf("Enter nepalese rupees: ");
    scanf("%d",&rupees);
    dollars=rupees/133.39;
    printf("%d rupees into dollars = %g\n",rupees,dollars);
    return 0;
}
