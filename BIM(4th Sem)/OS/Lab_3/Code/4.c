// WAP to implement priority scheduling

#include <stdio.h>

int main() {
    int n, i, j;
    int arrival[10], burst[10], priority[10];
    int completion[10], turnaround[10], waiting[10];
    int isCompleted[10] = {0};
    int currentTime = 0, completed = 0;
    float totalWaiting = 0, totalTurnaround = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time, burst time, and priority (lower number = higher priority) for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &burst[i]);
        printf("Process %d Priority: ", i + 1);
        scanf("%d", &priority[i]);
    }

    while(completed < n) {
        int idx = -1;
        int highestPriority = 100000;

        // Select process with highest priority among arrived and not completed
        for(i = 0; i < n; i++) {
            if(arrival[i] <= currentTime && !isCompleted[i]) {
                if(priority[i] < highestPriority) {
                    highestPriority = priority[i];
                    idx = i;
                } else if(priority[i] == highestPriority) {
                    // If same priority, choose earlier arrival time
                    if(arrival[i] < arrival[idx]) {
                        idx = i;
                    }
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
            currentTime++;
        }
    }

    printf("\nProcess\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival[i], burst[i], priority[i], completion[i], turnaround[i], waiting[i]);
    }

    printf("\nAverage Turnaround Time = %.2f\n", totalTurnaround / n);
    printf("Average Waiting Time = %.2f\n", totalWaiting / n);

    return 0;
}

