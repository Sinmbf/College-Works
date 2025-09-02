#include <stdio.h>

int main() {
    int frames, pages, pageFaults = 0, i, j, flag, hand = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int pageSeq[pages], frame[frames], refBit[frames];

    printf("Enter page reference string: ");
    for (i = 0; i < pages; i++)
        scanf("%d", &pageSeq[i]);

    // Initialize frames as empty (-1) and reference bits = 0
    for (i = 0; i < frames; i++) {
        frame[i] = -1;
        refBit[i] = 0;
    }

    // Process each page
    for (i = 0; i < pages; i++) {
        flag = 0;

        // Check if page is already present
        for (j = 0; j < frames; j++) {
            if (frame[j] == pageSeq[i]) {
                refBit[j] = 1;  // Give second chance
                flag = 1;
                break;
            }
        }

        // If not found ? Page fault occurs
        if (flag == 0) {
            while (1) {
                if (frame[hand] == -1) {  
                    // Empty frame ? place directly
                    frame[hand] = pageSeq[i];
                    refBit[hand] = 0;
                    hand = (hand + 1) % frames;
                    break;
                }
                else if (refBit[hand] == 0) {
                    // Replace this frame
                    frame[hand] = pageSeq[i];
                    refBit[hand] = 0;
                    hand = (hand + 1) % frames;
                    break;
                }
                else {
                    // Give second chance ? clear refBit and move hand
                    refBit[hand] = 0;
                    hand = (hand + 1) % frames;
                }
            }
            pageFaults++;
        }

        // Print current frame status
        printf("Step %2d: ", i + 1);
        for (j = 0; j < frames; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}

