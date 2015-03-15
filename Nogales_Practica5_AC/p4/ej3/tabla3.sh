#!/bin/bash

SIZE=$1

if [ $# -lt 1 ]; then
        echo "Faltan parametros"
else

echo "Tamaño del vector   " >  ./logs/log.0
echo "Optimizacion -O0  - " >> ./logs/log.0 
echo "Optimizacion -O1  - " >> ./logs/log.0 
echo "Optimizacion -O2  - " >> ./logs/log.0 
echo "Optimizacion -O3  - " >> ./logs/log.0 
echo "Optimizacion -Os  - " >> ./logs/log.0 

echo $(( $SIZE )) " "  > ./logs/O0
./daxpyO0 $SIZE >> ./logs/O0
./daxpyO1 $SIZE >> ./logs/O0
./daxpyO2 $SIZE >> ./logs/O0
./daxpyO3 $SIZE >> ./logs/O0
./daxpyOs $SIZE >> ./logs/O0

echo " " $(( $SIZE*10 )) " " > ./logs/O1
echo " `./daxpyO0 $(( 10*$SIZE ))`" >> ./logs/O1
echo " `./daxpyO1 $(( 10*$SIZE ))`" >> ./logs/O1
echo " `./daxpyO2 $(( 10*$SIZE ))`" >> ./logs/O1
echo " `./daxpyO3 $(( 10*$SIZE ))`" >> ./logs/O1
echo " `./daxpyOs $(( 10*$SIZE ))`" >> ./logs/O1

echo " "$(( $SIZE*100 )) " " > ./logs/O2
echo " `./daxpyO0 $(( 100*$SIZE ))`" >> ./logs/O2
echo " `./daxpyO1 $(( 100*$SIZE ))`" >> ./logs/O2
echo " `./daxpyO2 $(( 100*$SIZE ))`" >> ./logs/O2
echo " `./daxpyO3 $(( 100*$SIZE ))`" >> ./logs/O2
echo " `./daxpyOs $(( 100*$SIZE ))`" >> ./logs/O2

echo " "$(( $SIZE*1000 )) > " " > ./logs/O3
echo " `./daxpyO0 $(( 1000*$SIZE ))`" >> ./logs/O3
echo " `./daxpyO1 $(( 1000*$SIZE ))`" >> ./logs/O3
echo " `./daxpyO2 $(( 1000*$SIZE ))`" >> ./logs/O3
echo " `./daxpyO3 $(( 1000*$SIZE ))`" >> ./logs/O3
echo " `./daxpyOs $(( 1000*$SIZE ))`" >> ./logs/O3

paste ./logs/log.0 ./logs/O0 ./logs/O1 ./logs/O2 ./logs/O3 > ./logs/log_final

cat ./logs/log_final
fi
