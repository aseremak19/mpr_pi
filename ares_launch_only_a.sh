#!/bin/bash -l
#SBATCH --nodes 1
#SBATCH --ntasks 13
#SBATCH --time=01:00:00
#SBATCH --partition=plgrid
#SBATCH --account=plgmpr23-cpu
module add .plgrid plgrid/tools/openmpi
mpicc -o ares_small_a_c ares_small_a.c
mpicc -o ares_medium_a_c ares_medium_a.c
mpicc -o ares_big_a_c ares_big_a.c
mpicc -o ares_small_g_c ares_small_g.c
mpicc -o ares_medium_g_c ares_medium_g.c
mpicc -o ares_big_g_c ares_big_g.c
mpiexec -np 1 ./ares_small_a_c
mpiexec -np 2 ./ares_small_a_c
mpiexec -np 3 ./ares_small_a_c
mpiexec -np 4 ./ares_small_a_c
mpiexec -np 5 ./ares_small_a_c
mpiexec -np 6 ./ares_small_a_c
mpiexec -np 7 ./ares_small_a_c
mpiexec -np 8 ./ares_small_a_c
mpiexec -np 9 ./ares_small_a_c
mpiexec -np 10 ./ares_small_a_c
mpiexec -np 11 ./ares_small_a_c
mpiexec -np 12 ./ares_small_a_c
mpiexec -np 1 ./ares_medium_a_c
mpiexec -np 2 ./ares_medium_a_c
mpiexec -np 3 ./ares_medium_a_c
mpiexec -np 4 ./ares_medium_a_c
mpiexec -np 5 ./ares_medium_a_c
mpiexec -np 6 ./ares_medium_a_c
mpiexec -np 7 ./ares_medium_a_c
mpiexec -np 8 ./ares_medium_a_c
mpiexec -np 9 ./ares_medium_a_c
mpiexec -np 10 ./ares_medium_a_c
mpiexec -np 11 ./ares_medium_a_c
mpiexec -np 12 ./ares_medium_a_c
mpiexec -np 1 ./ares_big_a_c
mpiexec -np 2 ./ares_big_a_c
mpiexec -np 3 ./ares_big_a_c
mpiexec -np 4 ./ares_big_a_c
mpiexec -np 5 ./ares_big_a_c
mpiexec -np 6 ./ares_big_a_c
mpiexec -np 7 ./ares_big_a_c
mpiexec -np 8 ./ares_big_a_c
mpiexec -np 9 ./ares_big_a_c
mpiexec -np 10 ./ares_big_a_c
mpiexec -np 11 ./ares_big_a_c
mpiexec -np 12 ./ares_big_a_c