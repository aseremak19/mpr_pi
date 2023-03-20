#!/bin/bash -l
#SBATCH --nodes 1
#SBATCH --ntasks 12
#SBATCH --time=01:20:00
#SBATCH --partition=plgrid
#SBATCH --account=plgmpr23-cpu
module add .plgrid plgrid/tools/openmpi
mpicc -o ares_small_a_c ares_small_a.c
mpicc -o ares_small_a_c ares_small_a.c