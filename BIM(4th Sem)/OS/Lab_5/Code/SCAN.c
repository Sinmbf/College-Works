#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, j, dir, size, seek=0;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter request sequence: ");
    for (i=0;i<n;i++) scanf("%d",&req[i]);

    printf("Enter initial head position: ");
    scanf("%d",&head);

    printf("Enter total disk size: ");
    scanf("%d",&size);

    printf("Enter direction (1=right, 0=left): ");
    scanf("%d",&dir);

    // sort requests
    for (i=0;i<n-1;i++)
        for (j=i+1;j<n;j++)
            if (req[i]>req[j]) {
                int t=req[i]; req[i]=req[j]; req[j]=t;
            }

    int idx=0; while (idx<n && req[idx]<head) idx++;

    printf("\nSeek Sequence: %d", head);
    if (dir==1) {
        for (i=idx;i<n;i++) { seek += abs(head-req[i]); head=req[i]; printf(" -> %d", head); }
        seek += abs(head-(size-1)); head=size-1; printf(" -> %d", head);
        for (i=idx-1;i>=0;i--) { seek += abs(head-req[i]); head=req[i]; printf(" -> %d", head); }
    } else {
        for (i=idx-1;i>=0;i--) { seek += abs(head-req[i]); head=req[i]; printf(" -> %d", head); }
        seek += abs(head-0); head=0; printf(" -> %d", head);
        for (i=idx;i<n;i++) { seek += abs(head-req[i]); head=req[i]; printf(" -> %d", head); }
    }
    printf("\nTotal Seek Time = %d", seek);
    printf("\nAverage Seek Time = %.2f\n",(float)seek/n);
    return 0;
}

