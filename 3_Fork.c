#include <stdio.h>
#include <unistd.h>

int main()
{
    int id;
    printf("Hello World");
    id = fork();
    if (id > 0)
    {
        printf("This is a parent section[Process id:%d].\n", getpid());
    }
    else if (id == 0)
    {
        printf("fork created[process id: %d].\n", getpid());
        printf("fork parent process id: %d].\n", getppid());
    }
    else
    {
        printf("fork is not created");
    }
    return 0;
}
