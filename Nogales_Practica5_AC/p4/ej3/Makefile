###############################################################################
# Makefile
###############################################################################

SHELL = /bin/bash

SRC = $(wildcard *.c *.cc *.cpp)
EXE = $(basename $(SRC))
ATT = $(EXE:=.att)
TXT = machine.txt
TODO = void.txt

CFLAGS = -flto -fopenmp -fwhole-program -O3 -Wall -Wl,--no-as-needed
CXXFLAGS = $(CFLAGS) -std=c++0x
LDFLAGS = -lm -lrt

###############################################################################

default: $(EXE) $(TODO)

all: $(ATT) $(TXT) 

clean:
	$(RM) -fv $(ATT) $(EXE) $(TXT) core.* *~ *0 *1 *2 *3 *s ./logs/*

test: 1 1a
	for i in $^; do \
		time ./$$i; \
		echo "$$i --> $$?"; \
	done

###############################################################################

.PHONY: all clean default 

###############################################################################


void.txt:
	./todo3.sh

machine.txt: /proc/cpuinfo
	@printf '%80s\n' | tr ' ' - > $@; \
	echo "$(CC) -v" >> $@; \
	printf '%80s\n' | tr ' ' - >> $@; \
	$(CC) -v &>> $@; \
	printf '%80s\n' | tr ' ' - >> $@; \
	echo "cat /proc/cpuinfo" >> $@; \
	printf '%80s\n' | tr ' ' - >> $@; \
	cat /proc/cpuinfo >> $@; \
	printf '%80s\n' | tr ' ' - >> $@

%.att: %
	objdump -C -D $< > $@

###############################################################################

.NOEXPORT:

###############################################################################
