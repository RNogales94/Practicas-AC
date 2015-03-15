###############################################################################
# Makefile
###############################################################################

SHELL = /bin/bash

SRC = $(wildcard *.c *.cc *.cpp)
EXE = $(basename $(filter-out mpi-pi.c,$(SRC)))
ATT = $(EXE:=.att)
LOG = $(EXE:=.log)
SVG = $(EXE:=.svg)

CFLAGS = -fopenmp -Ofast -Wall -Wl,--no-as-needed
CXXFLAGS = $(CFLAGS) -D _GLIBCXX_USE_NANOSLEEP -std=c++0x
LDFLAGS = -lrt

###############################################################################

default: $(EXE)

all: pmv.svg

clean:
	$(RM) -fv $(ATT) $(EXE) $(LOG) $(SVG) core.* *~

###############################################################################

%.att: %
	objdump -C -d ./$< > ./$@

###############################################################################

%.log: %
	$(RM) -f ./$@; \
	for (( i=1; i<=8192; i*=2 )); do \
		echo "$$i $$(./$< $$i 2> /dev/null)" | tee -a $@; \
	done

pmv.svg: pmv.log pmv.9a.log pmv.9b.log pmv.10.log Makefile
	gnuplot <<< "\
		set terminal svg; \
		set output '$@'; \
		set grid; \
		set key bottom; \
		set xlabel 'N'; \
		set ylabel 'time'; \
		set logscale x 2; \
		set logscale y 10; \
		set xtics rotate; \
		set xtics (1, 2, 4, 8, 16, 32, 64, 128, 256, 512, '1ki' 1024, '2ki' 2048, '4ki' 4096, '8ki' 8192, '16ki' 16384, '32ki' 32768, '64ki' 65526, '128ki' 131072, '256ki' 262144, '512ki' 524288, '1Mi' 1048576, '2Mi' 2097152, '4Mi' 4194304, '8Mi' 8388608, '16Mi' 16777216, '32Mi' 33554432, '64Mi' 67108864, '128Mi' 134217728, '256Mi' 268435456, '512Mi' 536870912, '1Gi' 1073741824); \
		set ytics ('1ns' 1, '10ns' 10, '100ns' 100, '1us' 1000, '10us' 10000, '100us' 100000, '1ms' 1000000, '10ms' 10000000, '100ms' 100000000, '1s' 1000000000, '10s' 10000000000, '100s' 100000000000); \
		plot 'pmv.log'    u 1:2 w lp lc 1 pt 5 t 'pmv', \
		     'pmv.9a.log' u 1:2 w lp lc 2 pt 7 t 'pmv.9a', \
		     'pmv.9b.log' u 1:2 w lp lc 3 pt 9 t 'pmv.9b', \
		     'pmv.10.log' u 1:2 w lp lc 7 pt 11 t 'pmv.10'"

###############################################################################

.NOEXPORT:

###############################################################################
