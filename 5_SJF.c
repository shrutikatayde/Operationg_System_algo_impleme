#include <stdio.h>
void main()
{
    int bt[10] = {0}, tat[10] = {0}, at[10] = {0}, wt[10] = {0}, ct[10] = {0};
    int n, i, j, temp, p[10] = {0};
    float totalTAT = 0, totalWT = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter process name, arrival time & burst time:");
        scanf("%d %d %d", &p[i], &at[i], &bt[i]);
    }
    // Arrange Burst time and arrival time in ascending order
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (bt[i] < bt[j])
            {
                temp = p[j];
                p[j] = p[i];
                p[i] = temp;
                
                temp = at[j];
                at[j] = at[i];
                at[i] = temp;

                temp = bt[j];
                bt[j] = bt[i];
                bt[i] = temp;
            }
        }
    }
    // calculate completion time of processes
    ct[0] = at[0] + bt[0];
    for (i = 1; i < n; i++)
    {
        ct[i] = ct[i - 1] + bt[i];
    }
    // calculate turnaround time and waiting times
    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        totalTAT = totalTAT + tat[i];
    }
    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
        totalWT = totalWT + wt[i];
    }
    printf("Solution: \n\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\t\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\n\nAverage Turnaround Time = %f\n", totalTAT / n);
    printf("Average WT = %f\n\n", totalWT / n);
    ;
}