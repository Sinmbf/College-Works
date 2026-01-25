#include <stdio.h>

int findLRU(int time[], int n) {
    int i, min = time[0], pos = 0;
    for (i = 1; i < n; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int frames, pages, pageFaults = 0, i, j, k, pos, flag1, flag2, counter = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int pageSeq[pages], frame[frames], time[frames];

    printf("Enter page reference string: ");
    for (i = 0; i < pages; i++)
        scanf("%d", &pageSeq[i]);

    // Initialize frames as empty
    for (i = 0; i < frames; i++)
        frame[i] = -1;

    for (i = 0; i < pages; i++) {
        flag1 = flag2 = 0;

        // Check if page is already in frame
        for (j = 0; j < frames; j++) {
            if (frame[j] == pageSeq[i]) {
                counter++;
                time[j] = counter;  // update recent use
                flag1 = flag2 = 1;
                break;
            }
        }

        // If empty frame available
        if (flag1 == 0) {
            for (j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    counter++;
                    pageFaults++;
                    frame[j] = pageSeq[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        // If replacement needed
        if (flag2 == 0) {
            pos = findLRU(time, frames);
            counter++;
            pageFaults++;
            frame[pos] = pageSeq[i];
            time[pos] = counter;
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

