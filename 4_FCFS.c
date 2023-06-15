#include <stdio.h>
void main()
{
    int bt[10] = {0}, at[10] = {0}, ct[10] = {0}, tat[10] = {0}, wt[10] = {0};
    int n;
    float totalTAT = 0, totalWT = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the busrt time for each process");
    for (int i = 0; i < n; i++)
    {
        printf("\n Burst time process [%d]:", i);
        scanf("%d", &bt[i]);
    }
    ct[0] = at[0] + bt[0];
    for (int i = 0; i < n; i++)
    {
        ct[i] = ct[i - 1] + bt[i];
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        totalTAT = totalTAT + tat[i];
        wt[i] = tat[i] - bt[i];
        totalWT = totalWT + wt[i];
    }
    printf("Solution:\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\t\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("Average Turnaround Time = %f\n", totalTAT / n);
    printf("Average Waiting Time = %f\n", totalWT / n);
}
