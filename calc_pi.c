#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

double rand_0_1(void)
{
    return rand() / ((double)RAND_MAX);
}

int isInCircle()
{
    int N = 1000;
    int incircle = 0;
    int count = 0;

    double x;
    double y;
    int distance;
    int i;

    for (i = 0; i < N; i++)
    {
        x = rand_0_1();
        y = rand_0_1();

        if (x * x + y * y <= 1)
        {
            incircle++;
        }
    }

    return incircle;
}

float pi_number(int inCircle)
{

    float pi;
    pi = 4.0 * (float)inCircle / (float)1000;

    printf("Pi %f\n", pi);

    return pi;
}

int main(int argc, char **argv)
{
    int rank, size;

    // Initialize MPI
    MPI_Init(&argc, &argv);

    // Get the number of processes and the rank of the current process
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    char hostname[MPI_MAX_PROCESSOR_NAME];
    int len;
    MPI_Get_processor_name(hostname, &len);

    /*if (size != 2)
    {
        printf("This program should be run with exactly 2 processes.\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }*/

    pi_number(isInCircle());

    MPI_Finalize();

    return 0;
}
