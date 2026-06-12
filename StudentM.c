#include <stdio.h>

struct Student
{
    char name[50];
    int roll;
    int marks[5];
};

int main()
{
    int st;

    printf("Enter No. of Students: ");
    scanf("%d", &st);

    struct Student s[st];

    // INPUT
    for (int i = 0; i < st; i++)
    {
        printf("\nEnter Details of Student %d\n", i + 1);

        printf("Enter Name: ");
        scanf(" %49[^\n]", s[i].name);

        printf("Enter Roll No: ");
        scanf("%d", &s[i].roll);

        printf("Enter Marks of 5 Subjects:\n");

        for (int j = 0; j < 5; j++)
        {
            printf("Subject %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);
        }
    }

    printf("\n====================================================================================================\n");
    printf("%-15s %-10s %-6s %-6s %-6s %-6s %-6s %-8s %-8s\n",
           "Name", "Roll", "S1", "S2", "S3", "S4", "S5", "Total", "Avg");
    printf("====================================================================================================\n");

    int overallTotal = 0;

    // OUTPUT
    for (int i = 0; i < st; i++)
    {
        int total = 0;

        printf("%-15s %-10d",
               s[i].name,
               s[i].roll);

        for (int j = 0; j < 5; j++)
        {
            printf("%-6d ", s[i].marks[j]);
            total += s[i].marks[j];
        }

        float avg = total / 5.0;

        overallTotal += total;

        printf("%-8d %-8.2f\n", total, avg);
    }

    printf("====================================================================================================\n");

    float overallAvg = overallTotal / (float)(st * 5);

    printf("\nOverall Total Marks = %d\n", overallTotal);
    printf("Overall Average Marks = %.2f\n", overallAvg);

    // SUBJECT WISE TOPPERS
    printf("\n------------- SUBJECT WISE TOPPERS -------------\n");

    for (int j = 0; j < 5; j++)
    {
        int max = s[0].marks[j];
        int topperIndex = 0;

        for (int i = 1; i < st; i++)
        {
            if (s[i].marks[j] > max)
            {
                max = s[i].marks[j];
                topperIndex = i;
            }
        }

        printf("Subject %d Topper: %s (Marks = %d)\n",
               j + 1,
               s[topperIndex].name,
               max);
    }

    return 0;
}