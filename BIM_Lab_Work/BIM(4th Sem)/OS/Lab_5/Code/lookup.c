#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, dir, i, j, seek = 0;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    
    int req[n];
    printf("Enter request sequence: ");
    for (i = 0; i < n; i++) scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);
    
    printf("Enter direction (1 = up, 0 = down): ");
    scanf("%d", &dir);

    // Sort the requests
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (req[i] > req[j]) {
                int t = req[i]; req[i] = req[j]; req[j] = t;
            }

    // Split
    int idx = 0;
    while (idx < n && req[idx] < head) idx++;

    printf("\nSeek sequence: %d", head);

    if (dir == 1) {
        for (i = idx; i < n; i++) {
            seek += abs(head - req[i]);
            head = req[i];
            printf(" -> %d", head);
        }
        for (i = idx - 1; i >= 0; i--) {
            seek += abs(head - req[i]);
            head = req[i];
            printf(" -> %d", head);
        }
    } else {
        for (i = idx - 1; i >= 0; i--) {
            seek += abs(head - req[i]);
            head = req[i];
            printf(" -> %d", head);
        }
        for (i = idx; i < n; i++) {
            seek += abs(head - req[i]);
            head = req[i];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal Seek Time = %d\nAverage Seek Time = %.2f\n",
           seek, (float)seek / n);

    return 0;
}

