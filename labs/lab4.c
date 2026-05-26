#include <stdio.h>

struct Process
{
    int pid;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
};

int main()
{
    int n, timeQuantum;
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    int time = 0;
    int completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;

        printf("Enter burst time for Process %d: ", p[i].pid);
        scanf("%d", &p[i].burstTime);

        p[i].remainingTime = p[i].burstTime;
    }

    printf("Enter time quantum: ");
    scanf("%d", &timeQuantum);

    while (completed < n)
    {
        int done = 1;

        for (int i = 0; i < n; i++)
        {
            if (p[i].remainingTime > 0)
            {
                done = 0;

                if (p[i].remainingTime > timeQuantum)
                {
                    time += timeQuantum;
                    p[i].remainingTime -= timeQuantum;
                }
                else
                {
                    time += p[i].remainingTime;

                    p[i].waitingTime =
                        time - p[i].burstTime;

                    p[i].turnaroundTime =
                        p[i].waitingTime + p[i].burstTime;

                    totalWaitingTime += p[i].waitingTime;
                    totalTurnaroundTime += p[i].turnaroundTime;

                    p[i].remainingTime = 0;
                    completed++;
                }
            }
        }

        if (done)
        {
            break;
        }
    }

    printf("\nRound Robin Scheduling\n");

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