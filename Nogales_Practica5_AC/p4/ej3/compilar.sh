#!/bin/bash

g++ $1.cc -o $1O0 -O0 -lrt -std=c++0x 
g++ $1.cc -o $1O1 -O1 -lrt -std=c++0x 
g++ $1.cc -o $1O2 -O2 -lrt -std=c++0x 
g++ $1.cc -o $1O3 -O3 -lrt -std=c++0x 
g++ $1.cc -o $1Os -Os -lrt -std=c++0x 
