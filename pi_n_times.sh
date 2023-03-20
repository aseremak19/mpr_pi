#!/bin/bash
mpicc -o calc_pi_c calc_pi.c
mpiexec -machinefile ../allnodes -np 2 ./calc_pi_c
mpiexec -machinefile ../allnodes -np 3 ./calc_pi_c
mpiexec -machinefile ../allnodes -np 4 ./calc_pi_c
mpiexec -machinefile ../allnodes -np 5 ./calc_pi_c
mpiexec -machinefile ../allnodes -np 6 ./calc_pi_c
mpiexec -machinefile ../allnodes -np 7 ./calc_pi_c
mpiexec -machinefile ../allnodes -np 8 ./calc_pi_c
mpiexec -machinefile ../allnodes -np 9 ./calc_pi_c
mpiexec -machinefile ../allnodes -np 10 ./calc_pi_c
mpiexec -machinefile ../allnodes -np 11 ./calc_pi_c
mpiexec -machinefile ../allnodes -np 12 ./calc_pi_c
