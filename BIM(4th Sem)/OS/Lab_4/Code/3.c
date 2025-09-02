#include <stdio.h>

int fifoPageFaults(int pages[], int n, int frames) {
    int frame[frames], index = 0, faults = 0, i, j, flag;

    // Initialize frames as empty
    for (i = 0; i < frames; i++)
        frame[i] = -1;

    for (i = 0; i < n; i++) {
        flag = 0;
        // Check if page exists
        for (j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                break;
            }
        }
        // If not found ? replace using FIFO
        if (flag == 0) {
            frame[index] = pages[i];
            index = (index + 1) % frames;
            faults++;
        }
    }
    return faults;
}

int main() {
    int n, i, minF, maxF;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter page reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter min and max number of frames to test: ");
    scanf("%d %d", &minF, &maxF);

    printf("\nFrame Size  ->  Page Faults\n");
    for (i = minF; i <= maxF; i++) {
        printf("%5d      ->  %d\n", i, fifoPageFaults(pages, n, i));
    }

    return 0;
}

