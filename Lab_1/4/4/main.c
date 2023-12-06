// WAP to accept amount from the user and add 5% tax on it and display the total amount

#include<stdio.h>

int main(){
    int amount;
    float total_amount;
    printf("Enter the amount: ");
    scanf("%d",&amount);
    total_amount=amount+0.05*amount;
    printf("The total amount with tax = %.2f\n",total_amount);
    return 0;
}
