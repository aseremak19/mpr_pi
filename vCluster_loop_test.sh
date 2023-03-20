#!/bin/bash
mpicc -o calc_pi_c calc_pi.c

set loop=0
:loop
echo hello world
set /a loop=%loop%+1 
if "%loop%"=="2" goto next
goto loop

:next
echo This text will appear after repeating "hello world" for 2 times.

mpiexec -machinefile ../allnodes -np 2 ./calc_pi_c

