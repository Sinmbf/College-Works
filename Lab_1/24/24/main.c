// WAP to read age of three people and then find average age

#include<stdio.h>

int main(){
    float age1,age2,age3;
    float average;
    printf("Enter age of three people: \n");
    scanf("%f",&age1);
    scanf("%f",&age2);
    scanf("%f",&age3);
    average=((age1+age2+age3)/3);
    printf("The average age of three people = %g\n",average);
    return 0;
}

