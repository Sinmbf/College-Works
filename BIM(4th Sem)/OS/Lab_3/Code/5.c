// WAP to implement highest response ratio scheduling

#include <stdio.h>

int main() {
    int n, i, completed = 0;
    int arrival[10], burst[10], completion[10], turnaround[10], waiting[10];
    int isCompleted[10] = {0};
    float responseRatio[10];
    int currentTime = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time and burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &burst[i]);
    }

    while(completed < n) {
        int idx = -1;
        float highestResponseRatio = -1.0;

        for(i = 0; i < n; i++) {
            if(arrival[i] <= currentTime && !isCompleted[i]) {
                waiting[i] = currentTime - arrival[i];
                responseRatio[i] = ((float)(waiting[i] + burst[i])) / burst[i];
                if(responseRatio[i] > highestResponseRatio) {
                    highestResponseRatio = responseRatio[i];
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            currentTime += burst[idx];
            completion[idx] = currentTime;
            turnaround[idx] = completion[idx] - arrival[idx];
            waiting[idx] = turnaround[idx] - burst[idx];
            isCompleted[idx] = 1;
            completed++;
        } else {
            currentTime++; // No process arrived yet, increment time
        }
    }

    float totalWaiting = 0, totalTurnaround = 0;

    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for(i = 0; i < n; i++) {
        totalWaiting += waiting[i];
        totalTurnaround += turnaround[i];
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", i + 1, arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
    }

    printf("\nAverage Turnaround Time = %.2f\n", totalTurnaround / n);
    printf("Average Waiting Time = %.2f\n", totalWaiting / n);

    return 0;
}

