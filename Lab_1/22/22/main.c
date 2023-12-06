// WAP to read mark price of radio and find discount which is 30% of mark price then find the actual selling price of radio.

#include<stdio.h>

int main(){
    int MP,SP,discount;
    printf("Enter the mark price: ");
    scanf("%d",&MP);
    discount=(0.31)*MP;
    SP=MP-discount;
    printf("Selling price of the radio = %d\n", SP);
    return 0;
}
