#include<stdio.h>

int main(){
    int num,rem,sum=0;
    printf("Enter a three digit number: ");
    scanf("%d",&num);
    while(num!=0){
        rem=num%10;     // Get the remainder which is also the last digit
        sum+=rem;       // Add the remainder ( digits from last to first )
        num=num/10;     // Remove the already obtained digit from last to first
    }
    printf("The sum of the three digits number = %d\n",sum);
    return 0;
}
