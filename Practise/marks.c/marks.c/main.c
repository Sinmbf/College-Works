#include<stdio.h>

int readMarks(void);

int main(){
    int m1,m2,m3,m4,m5,total_marks;
    float percentage;
    m1=readMarks();
    m2=readMarks();
    m3=readMarks();
    m4=readMarks();
    m5=readMarks();
    total_marks=m1+m2+m3+m4+m5;
    percentage=(float)(total_marks*100)/500;
    printf("Total Marks Obtained = %d\nPercentage = %g%%\n",total_marks,percentage);
    return 0;
}

int readMarks(){
    int marks;
    printf("Enter marks: ");
    scanf("%d",&marks);
    return marks;
}
