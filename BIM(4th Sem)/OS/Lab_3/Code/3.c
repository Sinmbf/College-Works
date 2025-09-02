// WAP to implement round robin scheduling

#include <stdio.h>

int main() {
    int n, i, timeQuantum;
    int arrival[10], burst[10], remaining[10];
    int completion[10], waiting[10], turnaround[10];
    int currentTime = 0, done = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time and burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i]; // Initialize remaining burst time
    }

    printf("Enter time quantum: ");
    scanf("%d", &timeQuantum);

    int completed = 0;
    int queue[100], front = 0, rear = 0;
    int visited[10] = {0};

    // Enqueue processes that have arrived at time 0
    for(i = 0; i < n; i++) {
        if(arrival[i] <= currentTime && !visited[i]) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    while(completed < n) {
        if(front == rear) {
            // If queue empty, increment time until a process arrives
            currentTime++;
            for(i = 0; i < n; i++) {
                if(arrival[i] <= currentTime && !visited[i]) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int idx = queue[front++];
        
        if(remaining[idx] > timeQuantum) {
            currentTime += timeQuantum;
            remaining[idx] -= timeQuantum;
        } else {
            currentTime += remaining[idx];
            remaining[idx] = 0;
            completed++;
            completion[idx] = currentTime;
            turnaround[idx] = completion[idx] - arrival[idx];
            waiting[idx] = turnaround[idx] - burst[idx];
        }

        // Enqueue processes that have arrived during this time
        for(i = 0; i < n; i++) {
            if(arrival[i] <= currentTime && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        // If current process is not finished, enqueue it again
        if(remaining[idx] > 0) {
            queue[rear++] = idx;
        }
    }

    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", i+1, arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
    }

    float totalWaiting = 0, totalTurnaround = 0;
    for(i = 0; i < n; i++) {
        totalWaiting += waiting[i];
        totalTurnaround += turnaround[i];
    }

    printf("\nAverage Turnaround Time = %.2f\n", totalTurnaround / n);
    printf("Average Waiting Time = %.2f\n", totalWaiting / n);

    return 0;
}

