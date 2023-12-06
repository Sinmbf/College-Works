// WAP that asks the student marks obtained in 5 subjects. Display the marks as well as total marks obtained and percentage assuming full marks is 100

#include<stdio.h>

int main(){
    int m1,m2,m3,m4,m5,total_marks;
    float percentage;
    printf("Enter marks obtained in 5 subjects:\n");
    scanf("%d",&m1);
    scanf("%d",&m2);
    scanf("%d",&m3);
    scanf("%d",&m4);
    scanf("%d",&m5);
    total_marks=m1+m2+m3+m4+m5;
    percentage=(total_marks*100)/500;
    printf("Marks obtained: \n%d\n%d\n%d\n%d\n%d\n",m1,m2,m3,m4,m5);
    printf("Total marks obtained = %d\n",total_marks);
    printf("Percentage obtained = %g\n",percentage);
    return 0;
}
