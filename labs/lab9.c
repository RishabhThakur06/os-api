#include <stdio.h>
#include <stdbool.h>

#define MAX_PARTITIONS 10
#define MAX_PROCESSES 10

struct Partition
{
    int id;
    int size;
    bool allocated;
};

struct Process
{
    int id;
    int size;
    int partition_id;
};

struct Partition partitions[MAX_PARTITIONS];
struct Process processes[MAX_PROCESSES];

int num_partitions = 0;
int num_processes = 0;

void initializePartitions()
{
    partitions[0].id = 1;
    partitions[0].size = 50;
    partitions[0].allocated = false;

    partitions[1].id = 2;
    partitions[1].size = 100;
    partitions[1].allocated = false;

    partitions[2].id = 3;
    partitions[2].size = 500;
    partitions[2].allocated = false;

    num_partitions = 3;
}

void initializeProcesses()
{
    processes[0].id = 1;
    processes[0].size = 80;

    processes[1].id = 2;
    processes[1].size = 150;

    num_processes = 2;
}

void displayPartitions()
{
    printf("Partitions:\n");
    printf("ID\tSize\tAllocated\n");

    for (int i = 0; i < num_partitions; i++)
    {
        printf("%d\t%d\t%s\n",
               partitions[i].id,
               partitions[i].size,
               partitions[i].allocated ? "Yes" : "No");
    }

    printf("\n");
}

void displayProcesses()
{
    printf("Processes:\n");
    printf("ID\tSize\tPartition ID\n");

    for (int i = 0; i < num_processes; i++)
    {
        printf("%d\t%d\t%d\n",
               processes[i].id,
               processes[i].size,
               processes[i].partition_id);
    }

    printf("\n");
}

void firstFit()
{
    for (int i = 0; i < num_processes; i++)
    {
        for (int j = 0; j < num_partitions; j++)
        {
            if (!partitions[j].allocated &&
                partitions[j].size >= processes[i].size)
            {
                partitions[j].allocated = true;

                processes[i].partition_id = partitions[j].id;

                printf("Process %d allocated to Partition %d\n",
                       processes[i].id,
                       partitions[j].id);

                break;
            }
        }
    }
}

int main()
{
    initializePartitions();

    initializeProcesses();

    printf("Initial State:\n");

    displayPartitions();

    displayProcesses();

    firstFit();

    printf("After Allocation:\n");

    displayPartitions();

    displayProcesses();

    return 0;
}