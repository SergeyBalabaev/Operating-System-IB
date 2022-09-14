#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("I am alive!!\n");
    }
    else
    {
        sleep(30);
    }
    return 0;
}
