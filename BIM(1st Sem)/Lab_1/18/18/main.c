// WAP to find the square and cube of a given number

#include<stdio.h>
#include<math.h>

int main(){
    int num;
    float square,cube;
    printf("Enter a number: ");
    scanf("%d",&num);
    square=num*num;
    cube=square*num;
    printf("Sqaure of %d = %g\n",num,square);
    printf("Cube of %d = %g\n",num,cube);
    return 0;
}
