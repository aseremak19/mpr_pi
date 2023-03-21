#!/bin/bash
mpicc -o ares_small_a_VCluster_c ares_small_a_VCluster.c
mpiexec -machinefile ../allnodes -np 1 ./ares_small_a_VCluster_c
mpiexec -machinefile ../allnodes -np 2 ./ares_small_a_VCluster_c