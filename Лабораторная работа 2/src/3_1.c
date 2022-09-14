#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
	printf("PID=%d\n", getpid());
	printf("PPID= %d\n", getppid());
	return 0;
}
