#!/bin/bash -l
mpicc -o ares_small_a_c ares_small_a.c
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