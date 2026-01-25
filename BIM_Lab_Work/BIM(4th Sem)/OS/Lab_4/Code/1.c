#include <stdio.h>

int main() {
    int frames, pages, pageFaults = 0, i, j, k, flag, index = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int pageSeq[pages], frame[frames];

    printf("Enter page reference string: ");
    for (i = 0; i < pages; i++)
        scanf("%d", &pageSeq[i]);

    // Initialize frames with -1 (empty)
    for (i = 0; i < frames; i++)
        frame[i] = -1;

    // Page replacement process
    for (i = 0; i < pages; i++) {
        flag = 0;

        // Check if page already exists in frames
        for (j = 0; j < frames; j++) {
            if (frame[j] == pageSeq[i]) {
                flag = 1;
                break;
            }
        }

        // If not found ? Page Fault occurs
        if (flag == 0) {
            frame[index] = pageSeq[i];   // Replace using FIFO
            index = (index + 1) % frames;
            pageFaults++;
        }

        // Print current frame status
        printf("Step %2d: ", i + 1);
        for (k = 0; k < frames; k++) {
            if (frame[k] != -1)
                printf("%d ", frame[k]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}

