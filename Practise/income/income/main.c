/*
 
 below 50,000 --> class C
 50,001-3,00,000 --> class B
 3,00,001-10,00,000 --> class A
 above 1000000 --> class A+
 
 */

#include<stdio.h>

int main(){
    int income;
    printf("Enter annual income: ");
    scanf("%d",&income);
    if(income>1000000){
        printf("Class A+");
    }
    else if(income>=300001){
        printf("Class A");
    }
    else if(income>=50001){
        printf("Class B");
    }
    else{
        printf("Class C");
    }
    return 0;
}
