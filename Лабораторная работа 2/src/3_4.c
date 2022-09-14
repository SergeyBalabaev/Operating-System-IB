#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("PID = %d, PPID = %d\n", getpid(), getppid());
        sleep(2);
        printf("PID = %d, PPID = %d\n", getpid(), getppid());
    }
    else
    {
        sleep(1);
        exit(0);
    }
}
