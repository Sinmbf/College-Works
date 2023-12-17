#include<stdio.h>

int main(){
    int age1,age2,age3;
    float average;
    printf("Enter age of the first person: ");
    scanf("%d",&age1);
    printf("Enter age of the second person: ");
    scanf("%d",&age2);
    printf("Enter age of the third person: ");
    scanf("%d",&age3);
    average=(float)(age1+age2+age3)/3;
    printf("The average age of three people = %g\n",average);
    return 0;
}
