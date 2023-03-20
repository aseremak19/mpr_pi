#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>
#include <string.h>

double rand_0_1(void)
{
    return rand() / ((double)RAND_MAX);
}

int exists(const char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}

int isInCircle()
{
    int N = 1000;
    int incircle = 0;
    int count = 0;
    int sum = 0;

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

    // printf("Pi %f\n", pi);

    return pi;
}

//==================================================

int main(int argc, char **argv)
{
    int rank, size, i, j;
    double start_time, end_time, total_time, elapsed_time;
    double *time_array;
    int iterations_limit_actual = 10;
    int iterations_repeats = 10000;

    int iterations_limit = iterations_limit_actual * 2;

    // Initialize MPI
    MPI_Init(&argc, &argv);

    // Get the number of processes and the rank of the current process
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // printf("Rank: %d; size: %d", rank, size);

    char hostname[MPI_MAX_PROCESSOR_NAME];
    int len;
    MPI_Get_processor_name(hostname, &len);

    int file_exist = exists("cores_1000.csv");

    // creating CSV file
    FILE *file = NULL;
    if (rank == 0)
    {
        if (file_exist == 0)
        {
            file = fopen("cores_1000.csv", "w");
            // Write the header row to the output file
            fprintf(file, "Cores, Time\n");
        }
        else
        {
            file = fopen("cores_1000.csv", "a");
        }
        if (file == NULL)
        {
            printf("Error opening output file.\n");
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
    }

    /*if (size != 2)
    {
        printf("This program should be run with exactly 2 processes.\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }*/

    time_array = (double *)malloc((iterations_limit + 1) * sizeof(double));

    for (i = 0; i < iterations_limit / size; i++)
    {

        total_time = 0.0;

        for (j = 0; j < iterations_repeats; j++)
        {
            MPI_Barrier(MPI_COMM_WORLD);
            start_time = MPI_Wtime();

            pi_number(isInCircle());

            MPI_Barrier(MPI_COMM_WORLD);
            end_time = MPI_Wtime();

            elapsed_time = end_time - start_time;

            total_time = total_time + elapsed_time;
        }
        time_array[i] = total_time;
        printf("Iteration: %d; total time:%.15f\n", i, total_time);
    }

    total_time = 0.0;
    for (j = 0; j < iterations_limit; j++)
    {
        total_time = total_time + time_array[j];
    }
    printf("total TIme sum: %.15f", total_time);

    total_time = total_time / (double)iterations_limit_actual;

    if (rank == 0)
    {

        fprintf(file, "%d, %.30f\n", size, total_time);
        printf("Average time: %f\n", total_time);
    }

    free(time_array);

    if (rank == 0)
    {
        fclose(file);
    }

    printf("Rank: %d; Hostanme: %s\n", rank, hostname);
    MPI_Finalize();

    return 0;
}
