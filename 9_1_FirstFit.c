#include <stdio.h>
int main()
{
    int p, m;

    printf("Enter number of processes:");
    scanf("%d", &p);
    printf("Enter number of Memory blocks:");
    scanf("%d", &m);
    int sizeprocess[10], sizememory[10], i;
    for (i = 0; i < p; i++)
    {
        printf("Enter size of process %d:", i);
        scanf("%d", &sizeprocess[i]);
    }
    for (i = 0; i < m; i++)
    {
        printf("Enter size of memory % d: ", i);
        scanf("%d", &sizememory[i]);
    }
    int j;
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (sizememory[j] >= sizeprocess[i])
            {
                sizememory[j] = sizememory[j] - sizeprocess[i];
                printf("Allocating process %d to memory %d\n Size remaining in it after allocation % d\n\n", i, j, sizememory[j]);
                break;
            }
        }
        if (j == m)
        {
            printf("Not enough memory for process %d", i);
            break;
        }
    }
}