// WAP to implement shortest job first

#include <stdio.h>

int main() {
    int n, i, j;
    int arrival[10], burst[10], completion[10], turnaround[10], waiting[10];
    int isCompleted[10] = {0};
    int currentTime = 0, completed = 0;
    float totalWaiting = 0, totalTurnaround = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time and burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d Arrival Time: ", i+1);
        scanf("%d", &arrival[i]);
        printf("Process %d Burst Time: ", i+1);
        scanf("%d", &burst[i]);
    }

    while(completed < n) {
        int idx = -1;
        int minBurst = 100000;  // Large number to find minimum

        // Find process with minimum burst time among arrived and not completed
        for(i = 0; i < n; i++) {
            if(arrival[i] <= currentTime && !isCompleted[i]) {
                if(burst[i] < minBurst) {
                    minBurst = burst[i];
                    idx = i;
                } else if (burst[i] == minBurst) {
                    // If burst times are same, choose process with earlier arrival time
                    if(arrival[i] < arrival[idx])
                        idx = i;
                }
            }
        }

        if(idx != -1) {
            completion[idx] = currentTime + burst[idx];
            turnaround[idx] = completion[idx] - arrival[idx];
            waiting[idx] = turnaround[idx] - burst[idx];

            totalWaiting += waiting[idx];
            totalTurnaround += turnaround[idx];

            currentTime = completion[idx];
            isCompleted[idx] = 1;
            completed++;
        } else {
            // If no process has arrived yet, increment time
            currentTime++;
        }
    }

    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", i+1, arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
    }

    printf("\nAverage Turnaround Time = %.2f\n", totalTurnaround / n);
    printf("Average Waiting Time = %.2f\n", totalWaiting / n);

    return 0;
}

