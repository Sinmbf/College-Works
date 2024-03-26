#include<stdio.h>

int main(){
    int a[3][3],b[3][3],flag=1,i,j;
    printf("Enter 9 values for matrix A: ");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter 9 values for matrix B: ");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(a[i][j]!=b[i][j]){
                flag=0;
                break;
            }
        }
        
    }
    if(flag==1){
        printf("Identical");
    }
    else{
        printf("Not Identical");
    }
}
