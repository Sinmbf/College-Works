#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, j, done[100]={0}, seek=0, min, diff, pos;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter request sequence: ");
    for (i=0;i<n;i++) scanf("%d",&req[i]);

    printf("Enter initial head position: ");
    scanf("%d",&head);

    printf("\nSeek Sequence: %d", head);
    for (i=0;i<n;i++) {
        min = 1e9;
        pos = -1;
        for (j=0;j<n;j++) {
            if (!done[j]) {
                diff = abs(head-req[j]);
                if (diff < min) { min = diff; pos = j; }
            }
        }
        seek += min;
        head = req[pos];
        done[pos] = 1;
        printf(" -> %d", head);
    }
    printf("\nTotal Seek Time = %d", seek);
    printf("\nAverage Seek Time = %.2f\n",(float)seek/n);
    return 0;
}

