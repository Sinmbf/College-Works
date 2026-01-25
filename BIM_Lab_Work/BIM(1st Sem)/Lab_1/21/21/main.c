// WAP to ask number of quantities and price per quantity then find total price

#include<stdio.h>

int main(){
    int q,price,total_price;
    printf("Enter the number of quantitites: ");
    scanf("%d",&q);
    printf("Enter price per quantity: ");
    scanf("%d",&price);
    total_price=q*price;
    printf("Total price = %d\n",total_price);
    return 0;
}
