#include <stdio.h>

// Function declatation
int add(int n1,int n2){
    return n1+n2;
}

// Main Function
int main(){
    int n1,n2;
    printf("Enter a number: ");
    scanf("%d",&n1);
    printf("Enter another number: ");
    scanf("%d",&n2);
    printf("The sum of %d and %d is %d\n",n1,n2,add(n1,n2));
    return 0;
}
