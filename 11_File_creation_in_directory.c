#include <stdio.h>
#include <string.h>
void main()
{
    int i = 0, j = 0, ch;
    char mdname[10], fname[10][10], name[10];
    printf("Enter the directory name:");
    scanf("%s", mdname);
    do
    {
        printf("Enter file name to be created:");
        scanf("%s", name);
        strcpy(fname[j++], name);
        printf("Do you want to enter another file(yes - 1 or no - 0):");
        scanf("%d", &ch);
    } while (ch == 1);
    printf("Directory name is:%s\n", mdname);
    printf("Files names are:");
    for (i = 0; i < j; i++)
        printf("\n%s", fname[i]);
}