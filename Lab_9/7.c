// WAP to store average rainfall of the first half of year and then display them in the given 
// format.

#include<stdio.h>

// 3 Months ==> 3 Cities
struct rm{
    int ktm;
    int ndlhi;
    int bnk;
}rm[3];

int main(){
    int i,temp;
    char mnth[3][10]={"January","February","March"};
    char cty[3][10]={"Kathmandu","New Delhi","Bangkok"};
    printf("Enter average rainfall:\n");
    for(i=0;i<3;i++){
        temp=0;
        printf("For %s:\n",mnth[i]);
        printf("In %s: ",cty[temp]);
        scanf("%d",&rm[i].ktm);
        temp++;
        printf("In %s: ",cty[temp]);
        scanf("%d",&rm[i].ndlhi);
        temp++;
        printf("In %s: ",cty[temp]);
        scanf("%d",&rm[i].bnk);
    }
    printf("City Name    Jan  Feb  Mar\n");
    for(i=0;i<3;i++){
        printf("%-15s%-5d%-5d%-5d\n",cty[i],rm[i].ktm,rm[i].ndlhi,rm[i].bnk);
    }
    return 0;
}
