#!/bin/bash
gcc $1.c -o $1O0 -O0 -lrt 
gcc $1.c -o $1O1 -O1 -lrt 
gcc $1.c -o $1O2 -O2 -lrt 
gcc $1.c -o $1O3 -O3 -lrt 
gcc $1.c -o $1Os -Os -lrt 
