#include <stdio.h>
void main()
{
    int frag[25], b[25], p[25], i, j, nb, np, temp, lowest = 10000;
    int bf[25], ff[25]; // status of block and index of block
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of process: ");
    scanf("%d", &np);
    printf("\nEnter the size of the blocks:\n ");
    for (i = 1; i <= nb; i++)
    {
        printf(" Block %d: ", i);
        scanf("%d", &b[i]);
    }
    printf("Enter the size of the process:\n ");
    for (i = 1; i<=np; i++)
    {
        printf(" process %d: ", i);
        scanf("%d", &p[i]);
    }
    // determine best blocks for process as:
    for (i = 1; i <= np; i++) // for each process
    {
        for (j = 1; j <= nb; j++) // to each block
        {
            if (bf[j] != 1) // check if block is empty//to store status of the block(i.e 1 or 0) if 1:allocated 0 : unallocated
            {
                temp = b[j] - p[i]; // determine difference process vs block size
                if (temp >= 0)      // if block size is big then process size

                    if (lowest > temp) // find lowest temp [find best suitable process for a block]
                    {
                        ff[i] = j;
                        lowest = temp;
                    }
            }
        }
        frag[i] = lowest; // assign file to suitable block
        bf[ff[i]] = 1;    // to store status of the block(i.e 1 or 0) if 1: allocated 0: unallocated
        lowest = 10000;
    }
    printf("\nProcess No\tProcess Size \tBlock No\tBlock Size\tFragment ");
    for (i = 1; i <= np && ff[i] != 0; i++) // ff to store index no. of block that used by particulal file
        printf("\n % d\t\t % d\t\t % d\t\t % d\t\t % d ", i, p[i], ff[i], b[ff[i]], frag[i]);
}