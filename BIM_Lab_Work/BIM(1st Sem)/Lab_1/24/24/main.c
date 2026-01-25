// WAP to read age of three people and then find average age

#include<stdio.h>

int main(){
    int age1,age2,age3;
    float average;
    printf("Enter age of three people: \n");
    scanf("%d",&age1);
    scanf("%d",&age2);
    scanf("%d",&age3);
    average=(float)(age1+age2+age3)/3;
    printf("The average age of three people = %g\n",average);
    return 0;
}

