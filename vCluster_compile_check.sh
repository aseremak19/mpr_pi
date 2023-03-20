#!/bin/bash
mpicc -o ares_small_a_c ares_small_a.c
mpicc -o ares_medium_a_c ares_medium_a.c
mpicc -o ares_big_a_c ares_big_a.c

mpicc -o ares_small_g_c ares_small_g.c
mpicc -o ares_medium_g_c ares_medium_g.c
mpicc -o ares_big_g_c ares_big_g.c

mpiexec -machinefile ../allnodes -np 1 ./ares_small_a_c
mpiexec -machinefile ../allnodes -np 2 ./ares_small_a_c

mpiexec -machinefile ../allnodes -np 1 ./ares_medium_a_c
mpiexec -machinefile ../allnodes -np 2 ./ares_medium_a_c

mpiexec -machinefile ../allnodes -np 1 ./ares_big_a_c
mpiexec -machinefile ../allnodes -np 2 ./ares_big_a_c

mpiexec -machinefile ../allnodes -np 1 ./ares_small_g_c
mpiexec -machinefile ../allnodes -np 2 ./ares_small_g_c

mpiexec -machinefile ../allnodes -np 1 ./ares_medium_g_c
mpiexec -machinefile ../allnodes -np 2 ./ares_medium_g_c

mpiexec -machinefile ../allnodes -np 1 ./ares_big_g_c
mpiexec -machinefile ../allnodes -np 2 ./ares_big_g_c