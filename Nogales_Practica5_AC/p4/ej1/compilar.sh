#!/bin/bash

g++ $1.cc -o $1O0 -fopenmp -O0 -lrt -std=c++0x
g++ $1.cc -o $1O1 -fopenmp -O1 -lrt -std=c++0x
g++ $1.cc -o $1O2 -fopenmp -O2 -lrt -std=c++0x
g++ $1.cc -o $1O3 -fopenmp -O3 -lrt -std=c++0x
g++ $1.cc -o $1Os -fopenmp -Os -lrt -std=c++0x
