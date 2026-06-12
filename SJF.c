#include<stdio.h>

struct Process {
    int pid;
    int bt;
    int wt;
    int tat;
};

int main(){
    int n;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct Process p[n], temp;

    // Input
    printf("Enter Burst Time:\n");
    for(int i=0;i<n;i++){
        p[i].pid = i + 1;
        printf("P%d: ", p[i].pid);
        scanf("%d",&p[i].bt);
    }

    // Sort by Burst Time (ascending)
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].bt > p[j].bt){
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // First process
    p[0].wt = 0;
    p[0].tat = p[0].bt;

    // Remaining processes
    for(int i=1;i<n;i++){
        p[i].wt = p[i-1].wt + p[i-1].bt;
        p[i].tat = p[i].wt + p[i].bt;
    }

    // Output
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].bt,
               p[i].wt,
               p[i].tat);
    }

    return 0;
}