#include<stdio.h>
#include<stdlib.h>

void factorial(int);
void armstrong(int);
void odd_even(int);

int main(){
    int choice,num;
    do{
        printf("****MENU****\n");
        printf("\n1.Factorial\n2.Armstrong\n3.Odd Or Even\n4.Exit\n");
        printf("\n************\n");
        printf("Enter a number: ");
        scanf("%d",&num);
        printf("Which operation do you want to perform?[1-4] ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                factorial(num);
                break;
            case 4:
                exit(1);
            default:
                printf("Invalid choice");
        }
    }while(choice!=4);
}

void factorial(int n){
    int i,fact=1;
    for(i=1;i<=n;i++){
        fact*=1;
    }
    printf("The factorial of %d is %d\n",n,fact);
}
