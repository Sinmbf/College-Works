// WAP to calculate the square root of the number inputted by the user

#include<stdio.h>
#include<math.h>

int main(){
    int n;
    float sqrt_root;
    printf("Enter a number: ");
    scanf("%d",&n);
    sqrt_root=sqrt(n);
    printf("Square root of %d = %.2f\n",n,sqrt_root);
    return 0;
}
