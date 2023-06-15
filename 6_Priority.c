#include <stdio.h>
void main()
{
    int at[10] = {0}, bt[10] = {0}, ct[10] = {0}, tat[10] = {0}, wt[10] = {0};
    int n, i, j, temp, p[10] = {0}, pp[10] = {0};
    float totalTAT = 0, totalWT = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the process name, burst time & priority: ");
        scanf("%d %d %d", &p[i], &bt[i], &pp[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (pp[j] < pp[i])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pp[i];
                pp[i] = pp[j];
                pp[j] = temp;
            }
        }
    }
    ct[0] = at[0] + bt[0];
    for (i = 1; i < n; i++)
    {
        ct[i] = ct[i - 1] + bt[i];
    }
    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        totalTAT = totalTAT + tat[i];
    }
    for (i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
        totalWT = totalWT + wt[i];
    }
    printf("Solution: \n\n");
    printf("Process\tAT\tBT\tPriority\tCT\tTAT\tWT\t\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", p[i], at[i], bt[i], pp[i], ct[i], tat[i], wt[i]);
    }
    printf("\n\nAverage Turnaround Time = %f\n", totalTAT / n);
    printf("Average WT = %f\n\n", totalWT / n);
}
