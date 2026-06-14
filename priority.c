#include <stdio.h>

struct Process {
    int pid;
    int bt;      // Burst Time
    int priority;
    int wt;      // Waiting Time
    int tat;     // Turnaround Time
};

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n], temp;

    // Input
    for(int i = 0; i < n; i++) {
        printf("\nEnter Process ID: ");
        scanf("%d", &p[i].pid);

        printf("Enter Burst Time: ");
        scanf("%d", &p[i].bt);

        printf("Enter Priority (Smaller number = Higher Priority): ");
        scanf("%d", &p[i].priority);
    }

    // Sort according to Priority
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(p[i].priority > p[j].priority) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate Waiting Time
    p[0].wt = 0;

    for(int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }

    // Calculate Turnaround Time
    for(int i = 0; i < n; i++) {
        p[i].tat = p[i].wt + p[i].bt;
    }

    // Calculate Average WT and TAT
    float totalWT = 0, totalTAT = 0;

    for(int i = 0; i < n; i++) {
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
    }

    // Output
    printf("\n==========================================================================\n");
    printf("%-10s %-12s %-12s %-15s %-15s\n",
           "PID", "Priority", "Burst", "Waiting", "Turnaround");
    printf("--------------------------------------------------------------------------\n");

    for(int i = 0; i < n; i++) {
        printf("%-10d %-12d %-12d %-15d %-15d\n",
               p[i].pid,
               p[i].priority,
               p[i].bt,
               p[i].wt,
               p[i].tat);
    }

    printf("==========================================================================\n");

    printf("\nAverage Waiting Time = %.2f", totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);

    return 0;
}
