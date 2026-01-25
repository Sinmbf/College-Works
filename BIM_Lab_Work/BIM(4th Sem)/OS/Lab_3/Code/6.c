#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int main() {
    int n, m;
    int i, j, k;

    // Number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Number of resources
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int max[MAX_PROCESSES][MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int available[MAX_RESOURCES];
    int finish[MAX_PROCESSES] = {0};
    int safeSequence[MAX_PROCESSES];

    // Input Allocation Matrix
    printf("Enter Allocation Matrix (%d x %d):\n", n, m);
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Input Max Matrix
    printf("Enter Max Matrix (%d x %d):\n", n, m);
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }                              

    // Input Available resources
    printf("Enter Available Resources (%d):\n", m);
    for(i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    // Calculate Need Matrix = Max - Allocation
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int count = 0;
    while(count < n) {
        int found = 0;
        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int canAllocate = 1;
                for(j = 0; j < m; j++) {
                    if(need[i][j] > available[j]) {
                        canAllocate = 0;
                        break;
                    }
                }

                if(canAllocate) {
                    for(k = 0; k < m; k++) {
                        available[k] += allocation[i][k];
                    }
                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if(found == 0) {
            break; // No safe process found in this iteration
        }
    }

    if(count == n) {
        printf("System is in a safe state.\nSafe sequence is: ");
        for(i = 0; i < n; i++) {
            printf("P%d ", safeSequence[i]);
        }
        printf("\n");
    } else {
        printf("System is NOT in a safe state.\n");
    }

    return 0;
}
