#include <stdio.h>

int main() {
    int nb, np, i, j;
    printf("Enter number of blocks: ");
    scanf("%d", &nb);

    int block[nb], allocated[nb];
    printf("Enter sizes of blocks: ");
    for (i = 0; i < nb; i++) {
        scanf("%d", &block[i]);
        allocated[i] = 0; // initially free
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int process[np], assign[np];
    printf("Enter sizes of processes: ");
    for (i = 0; i < np; i++) {
        scanf("%d", &process[i]);
        assign[i] = -1; // not allocated
    }

    // Worst Fit Allocation
    for (i = 0; i < np; i++) {
        int worst = -1;
        for (j = 0; j < nb; j++) {
            if (!allocated[j] && block[j] >= process[i]) {
                if (worst == -1 || block[j] > block[worst])
                    worst = j;
            }
        }
        if (worst != -1) {
            assign[i] = worst;
            allocated[worst] = 1;
        }
    }

    // Print allocation result
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i + 1, process[i]);
        if (assign[i] != -1)
            printf("%d\n", assign[i] + 1);
        else
            printf("Not Allocated\n");
    }
    return 0;
}

