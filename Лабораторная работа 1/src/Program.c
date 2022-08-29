#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	double N = atof(argv[2]);
	if(strcmp(argv[1], "sin") == 0)
		printf("Sin(%lf)=%lf\n", N, sin(N/180*M_PI));
	else 
		printf("Error...");
	return 0;
}
