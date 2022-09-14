#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    pid_t PID = fork();
    if (PID == 0)
    {
        printf("Hello ");
        sleep(30);
    }
    else
    {
        wait(0);
        printf("world!\n");
    }
    return 0;
}
