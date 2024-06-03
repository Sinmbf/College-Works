#include <stdio.h>
int main()
{
int num=212, i;
printf("Right shift by %d: %d\n", 0, num>>0); printf("Right shift by %d: %d\n", 1, num>>1); printf("Right shift by %d: %d\n", 2, num>>2);
printf("\n");
printf("Left shift by %d: %d\n", 0, num<<0); printf("Left shift by %d: %d\n", 1, num<<1); printf("Left shift by %d: %d\n", 2, num<<2);
    return 0;
}
