#!/bin/bash -l
mpicc -o ares_medium_a_c ares_medium_a.c
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