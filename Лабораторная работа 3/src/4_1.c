#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

// Input arguments:
// 1: Начало интервала
// 2: Конец интервала
// 3: Число разбиений
//
// example:
//  ./integral 0 10 1000000

double integrate(double a, double b, int n)
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
	I = integrate(strtod(argv[1], 0), strtod(argv[2], 0), N);
	printf("I = %f\n", I);

	return 0;
}
