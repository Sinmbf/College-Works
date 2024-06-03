// WAP that accept the selling price of an item in supermarket in Indian currency and display the selling price in Nepalese currency

#include<stdio.h>

int main(){
    int Indian_SP;
    float Nepalese_SP;
    printf("Enter the selling price in Indian Currency: ");
    scanf("%d",&Indian_SP);
    Nepalese_SP=Indian_SP*1.60;
    printf("%d selling price in Indian currency = %g selling price in Nepalse currency\n",Indian_SP,Nepalese_SP);
    return 0;
}
