#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, seek = 0;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter request sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d", head);
    for (i = 0; i < n; i++) {
        seek += abs(head - req[i]);
        head = req[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time = %d", seek);
    printf("\nAverage Seek Time = %.2f\n", (float)seek / n);

    return 0;
}

