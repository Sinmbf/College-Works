// WAP to convert hour into minute, minute into second [ 1hr=60mins and 1min=60seconds]

#include<stdio.h>

int main(){
    int hr,min,sec;
    printf("Enter time in hours: ");
    scanf("%d",&hr);
    min=hr*60;
    sec=min*60;
    printf("%d hours into minutes = %d\n",hr,min);
    printf("%d hour into seconds = %d\n",hr,sec);
    return 0;
}
