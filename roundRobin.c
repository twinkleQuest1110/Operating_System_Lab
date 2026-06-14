#include <stdio.h>

struct Process {
    int pid;
    int bt;      // Burst Time
    int rt;      // Remaining Time
    int wt;      // Waiting Time
    int tat;     // Turnaround Time
};

int main() {
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input
    for(int i = 0; i < n; i++) {
        printf("\nEnter Process ID: ");
        scanf("%d", &p[i].pid);

        printf("Enter Burst Time: ");
        scanf("%d", &p[i].bt);

        p[i].rt = p[i].bt;
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);

    int completed = 0;
    int time = 0;

    while(completed < n) {

        for(int i = 0; i < n; i++) {

            if(p[i].rt > 0) {

                if(p[i].rt <= tq) {
                    time += p[i].rt;
                    p[i].rt = 0;
                    completed++;

                    p[i].tat = time;
                    p[i].wt = p[i].tat - p[i].bt;
                }
                else {
                    time += tq;
                    p[i].rt -= tq;
                }
            }
        }
    }

    float totalWT = 0, totalTAT = 0;

    printf("\n====================================================================\n");
    printf("%-10s %-15s %-15s %-15s\n",
           "PID", "Burst Time", "Waiting", "Turnaround");
    printf("--------------------------------------------------------------------\n");

    for(int i = 0; i < n; i++) {

        totalWT += p[i].wt;
        totalTAT += p[i].tat;

        printf("%-10d %-15d %-15d %-15d\n",
               p[i].pid,
               p[i].bt,
               p[i].wt,
               p[i].tat);
    }

    printf("====================================================================\n");

    printf("\nAverage Waiting Time = %.2f", totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);

    return 0;
}
