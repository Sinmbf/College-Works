// WAP that read two variables and swap the data between two variables

#include<stdio.h>

int main(){
    int temp=0,n1,n2;
    printf("Enter two numbers: \n");
    scanf("%d",&n1);
    scanf("%d",&n2);
    temp=n1;
    n1=n2;
    n2=temp;
    printf("Swapped values: \nn1=%d\nn2=%d\n",n1,n2);
    return 0;
}

