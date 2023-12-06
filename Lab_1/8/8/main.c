// WAP that reads a character data and display its ASCII value

#include<stdio.h>

int main(){
    char ch;
    printf("Enter a character: ");
    scanf("%c",&ch);
    
    // %d displays the integer value of a character
    // %c displays the actual character
    
    printf("ASCII value of %c is %d\n",ch,ch);
    return 0;
}
