// WAP to convert meter into centimeter [ 1m=100cm]

#include<stdio.h>

int main(){
    int m,cm;
    printf("Enter number in meters: ");
    scanf("%d",&m);
    cm=m*100;
    printf("%d m into cm = %d\n",m, cm);
    return 0;
}
