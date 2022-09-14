#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(void)
{
    int fd[2];
    pid_t pid;
    char string[] = "Hello, Parent!\n";
    char readbuffer[80];
    pipe(fd);
    pid = fork();
    if (pid == 0)
    {
        close(fd[0]);
        write(fd[1], string, (strlen(string) + 1));
        exit(0);
    }
    else
    {
        close(fd[1]);
        read(fd[0], readbuffer, sizeof(readbuffer));
        printf("Parent received: %s", readbuffer);
    }

    return (0);
}
