#include <stdio.h>

int predict(int pages[], int frames[], int n, int totalPages, int index) {
    int i, j, farthest = index, pos = -1, found;
    
    for (i = 0; i < n; i++) {
        found = 0;
        for (j = index; j < totalPages; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                found = 1;
                break;
            }
        }
        if (!found)  // Page not used again ? best candidate to replace
            return i;
    }
    
    if (pos == -1)
        return 0;
    return pos;
}

int main() {
    int frames, pagesCount, pageFaults = 0, i, j, k, index, flag;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pagesCount);

    int pages[pagesCount], frame[frames];

    printf("Enter page reference string: ");
    for (i = 0; i < pagesCount; i++)
        scanf("%d", &pages[i]);

    // Initialize frames as empty
    for (i = 0; i < frames; i++)
        frame[i] = -1;

    for (i = 0; i < pagesCount; i++) {
        flag = 0;

        // Check if page is already in frame
        for (j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        // If not found ? page fault
        if (flag == 0) {
            // Find empty frame
            for (j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    frame[j] = pages[i];
                    flag = 1;
                    pageFaults++;
                    break;
                }
            }
        }

        // If all frames full ? replace optimal
        if (flag == 0) {
            index = predict(pages, frame, frames, pagesCount, i + 1);
            frame[index] = pages[i];
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

