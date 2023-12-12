// WAP that accepts dollar from user and calculate the equivalent Nepalese rupees and display the result

#include<stdio.h>

int main(){
    float dollar,nep_rupees;
    printf("Enter dollar amount: ");
    scanf("%f",&dollar);
    nep_rupees=dollar*133.33;
    printf("%g dollars into nepalese rupees = %.2f\n",dollar,nep_rupees);
    return 0;
}
