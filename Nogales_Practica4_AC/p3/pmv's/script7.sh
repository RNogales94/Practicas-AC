#!/bin/bash

size=10000

echo "Chunk" > ./logs/log.0 
echo 1 >> ./logs/log.0
echo 2 >> ./logs/log.0
echo 32 >> ./logs/log.0
echo 64 >> ./logs/log.0
echo 2048 >> ./logs/log.0

echo "Static" > ./logs/s
./pmtv-OpenMP-static 1 $size ok >> ./logs/s
./pmtv-OpenMP-static 2 $size ok >> ./logs/s
./pmtv-OpenMP-static 32 $size ok >> ./logs/s
./pmtv-OpenMP-static 64 $size ok >> ./logs/s
./pmtv-OpenMP-static 2048 $size ok >> ./logs/s

echo "        Dynamic" > ./logs/d
./pmtv-OpenMP-dynamic 1 $size ok >> ./logs/d
./pmtv-OpenMP-dynamic 2 $size ok >> ./logs/d
./pmtv-OpenMP-dynamic 32 $size ok >> ./logs/d
./pmtv-OpenMP-dynamic 64 $size ok >> ./logs/d
./pmtv-OpenMP-dynamic 2048 $size ok >> ./logs/d

echo "        Guided" > ./logs/g
./pmtv-OpenMP-guided 1 $size ok >> ./logs/g
./pmtv-OpenMP-guided 2 $size ok >> ./logs/g
./pmtv-OpenMP-guided 32 $size ok >> ./logs/g
./pmtv-OpenMP-guided 64 $size ok >> ./logs/g
./pmtv-OpenMP-guided 2048 $size ok >> ./logs/g


paste ./logs/log.0 ./logs/s ./logs/d ./logs/g > ./logs/log_final

cat ./logs/log_final
