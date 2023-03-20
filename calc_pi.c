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

int main(int argc, char **argv, char *cores)
{
    int rank, size, i, j;
    double start_time, end_time, total_time, elapsed_time;
    int *time_array;
    int iterations_limit = 10000;

    int iterations_per_sequence = 100;

    // Initialize MPI
    MPI_Init(&argc, &argv);

    // Get the number of processes and the rank of the current process
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    char hostname[MPI_MAX_PROCESSOR_NAME];
    int len;
    MPI_Get_processor_name(hostname, &len);

    char string_file[20] = "_cores_1000.csv";

    // string_file = "_cores_1000.csv";

    strcat(cores, string_file);

    // printf("No of cores: %s", &no_cores);

    // creating CSV file
    FILE *file = NULL;
    if (rank == 0)
    {
        file = fopen("2_cores_1000.csv", "w");
        if (file == NULL)
        {
            printf("Error opening output file.\n");
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        // Write the header row to the output file
        fprintf(file, "Array Size,Average Time\n");
    }

    /*if (size != 2)
    {
        printf("This program should be run with exactly 2 processes.\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }*/

    time_array = (int *)malloc((iterations_limit + 1) * sizeof(int));

    for (i = 0; i < iterations_limit; i++)
    {

        MPI_Barrier(MPI_COMM_WORLD);
        start_time = MPI_Wtime();

        for (j = 0; j < iterations_per_sequence; j++)
        {

            pi_number(isInCircle());
        }
        end_time = MPI_Wtime();

        elapsed_time = start_time - end_time;
        time_array[j] = elapsed_time;
    }

    total_time = 0.0;
    for (j = 0; j < iterations_per_sequence; j++)
    {
        total_time = total_time + time_array[j];
    }

    total_time = total_time / (double)iterations_per_sequence;

    if (rank == 0)
    {

        fprintf(file, "%.30f\n", total_time);
    }

    free(time_array);

    printf("Rank: %d; Hostanme: %s\n", rank, hostname);
    MPI_Finalize();

    return 0;
}
