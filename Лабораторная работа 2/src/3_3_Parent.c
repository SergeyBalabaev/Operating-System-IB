#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    execl("child", "child", NULL);
    printf("I am Parent!\n");
    sleep(30);
    return 0;
}
