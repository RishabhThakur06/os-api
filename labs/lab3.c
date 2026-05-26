#include <stdio.h>

struct Process
{
    int pid;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

int main()
{
    int n;
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;

        printf("Enter burst time for Process %d: ", p[i].pid);
        scanf("%d", &p[i].burstTime);
    }

    p[0].waitingTime = 0;

    for (int i = 1; i < n; i++)
    {
        p[i].waitingTime = p[i - 1].waitingTime + p[i - 1].burstTime;
    }

    for (int i = 0; i < n; i++)
    {
        p[i].turnaroundTime = p[i].waitingTime + p[i].burstTime;

        totalWaitingTime += p[i].waitingTime;
        totalTurnaroundTime += p[i].turnaroundTime;
    }

    printf("\nFCFS Scheduling\n");

    printf("\nPID\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n",
               p[i].pid,
               p[i].burstTime,
               p[i].waitingTime,
               p[i].turnaroundTime);
    }

    printf("\nAverage Waiting Time = %.2f\n",
           (float)totalWaitingTime / n);

    printf("Average Turnaround Time = %.2f\n",
           (float)totalTurnaroundTime / n);

    return 0;
}