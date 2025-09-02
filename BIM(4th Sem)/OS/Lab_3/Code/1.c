// WAP to implement first-come-first-serve

#include <stdio.h>

int main() {
    int n, i;
    int arrival[10], burst[10], completion[10], turnaround[10], waiting[10];
    int total_waiting = 0, total_turnaround = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time and burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d Arrival Time: ", i+1);
        scanf("%d", &arrival[i]);
        printf("Process %d Burst Time: ", i+1);
        scanf("%d", &burst[i]);
    }

    // Completion time calculation for FCFS
    completion[0] = arrival[0] + burst[0];
    for(i = 1; i < n; i++) {
        if(arrival[i] > completion[i-1])
            completion[i] = arrival[i] + burst[i];
        else
            completion[i] = completion[i-1] + burst[i];
    }

    // Calculate turnaround time and waiting time
    for(i = 0; i < n; i++) {
        turnaround[i] = completion[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];
        total_waiting += waiting[i];
        total_turnaround += turnaround[i];
    }

    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", i+1, arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
    }

    printf("\nAverage Turnaround Time = %.2f\n", (float)total_turnaround / n);
    printf("Average Waiting Time = %.2f\n", (float)total_waiting / n);

    return 0;
}

