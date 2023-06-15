#include <stdio.h>
void main()
{
    int buffer[10], in, out, produce, consume, choice = 0;
    in = 0, out = 0;
    int count = 0, n = 5;
    while (choice != 3)
    {
        printf("\n1. Produce \t 2. Consume \t3. Exit");
        printf("\nEnter your choice: =");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (count == n)
                printf("\nBuffer is Full");
            else
            {
                printf("\nEnter the value: ");
                scanf("%d", &produce);
                buffer[in] = produce;
                in = (in + 1) % n;
                count += 1;
            }
            break;
        case 2:
            if (count == 0)
                printf("\nBuffer is Empty");
            else
            {
                consume = buffer[out];
                printf("\nThe consumed value is %d", consume);
                out = (out + 1) % n;
                count = count - 1;
            }
            break;
        }
    }
}
