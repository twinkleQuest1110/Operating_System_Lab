#include<stdio.h>

struct Process{
    int pid;
    int bt;     // Burst Time / Execution Time
    int wt;     // Waiting Time
    int tat;    // Turnaround Time
};

int main(){

    int n;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct Process p[n];

    // Input
    for(int i=0; i<n; i++){

        printf("\nEnter Process ID: ");
        scanf("%d",&p[i].pid);

        printf("Enter Execution Time: ");
        scanf("%d",&p[i].bt);
    }

    // FCFS Calculation
    p[0].wt = 0;

    for(int i=1; i<n; i++){
        p[i].wt = p[i-1].wt + p[i-1].bt;
    }

    for(int i=0; i<n; i++){
        p[i].tat = p[i].wt + p[i].bt;
    }

    // Average Calculation
    float totalWT = 0, totalTAT = 0;

    for(int i=0; i<n; i++){
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
    }

    float avgWT = totalWT / n;
    float avgTAT = totalTAT / n;

    // Output Table
    printf("\n=============================================================\n");

    printf("%-10s %-15s %-15s %-15s\n",
           "PID",
           "Exec Time",
           "Waiting Time",
           "Turnaround");

    printf("----------------------------------------------------------------\n");

    for(int i=0; i<n; i++){

        printf("%-10d %-15d %-15d %-15d\n",
               p[i].pid,
               p[i].bt,
               p[i].wt,
               p[i].tat);
    }

    printf("=============================================================\n");

    printf("\nAverage Waiting Time = %.2f", avgWT);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);

    return 0;
}