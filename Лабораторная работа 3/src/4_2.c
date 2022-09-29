#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>

double integrate(double a, double b, double n)
{

    //тут будет ваш код
}

int main(int argc, char *argv[])
{
    double I;
    if (argc != 4)
    {
        fprintf(stderr, "Not enough arguments\n");
        exit(1);
    }
    long int N = atoi(argv[3]);

    int n;
    int fds[2];
    pid_t pid;
    pipe(fds);
    pid = fork();
    if (pid != (pid_t)0)
    {
        double r1 = 0, r2 = 0;
        int s;
        close(fds[1]);
        r1 = integrate(strtod(argv[1], 0), strtod(argv[2], 0) / 2, N / 2);
        read(fds[0], &r2, sizeof(double));
        close(fds[0]);
        printf("I = %g\n", r1 + r2);
        wait(&s);
        return 0;
    }
    else
    {
        double s;
        close(fds[0]);
        s = integrate(strtod(argv[2], 0) / 2, strtod(argv[2], 0), N / 2);
        write(fds[1], &s, sizeof(double));
        close(fds[1]);
        return 0;
    }
}
