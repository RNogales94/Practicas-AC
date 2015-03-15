#!/bin/bash

SIZE=$1

echo "Modificación  - - - - " > ./logs/log.0 
echo "Sin Modificar - - - - " >> ./logs/log.0
echo "ModificadoA - - - - " >> ./logs/log.0
echo "ModificadoB - - - - " >> ./logs/log.0

echo "   O0    " > ./logs/O0
./pmm-secuencialO0 $SIZE >> ./logs/O0
./pmm-secuencial-modificadoAO0 $SIZE>> ./logs/O0
./pmm-secuencial-modificadoBO0 $SIZE>> ./logs/O0


echo "   O1    " > ./logs/O1
./pmm-secuencialO1  $SIZE >> ./logs/O1
./pmm-secuencial-modificadoAO1  $SIZE >> ./logs/O1
./pmm-secuencial-modificadoBO1  $SIZE >> ./logs/O1

echo "   O2    " > ./logs/O2
./pmm-secuencialO2  $SIZE >> ./logs/O2
./pmm-secuencial-modificadoAO2  $SIZE >> ./logs/O2
./pmm-secuencial-modificadoBO2  $SIZE >> ./logs/O2


echo "  O3    " > ./logs/O3
./pmm-secuencialO3  $SIZE >> ./logs/O3
./pmm-secuencial-modificadoAO3 $SIZE >> ./logs/O3
./pmm-secuencial-modificadoBO3 $SIZE >> ./logs/O3

echo "   Os    " > ./logs/Os
./pmm-secuencialOs  $SIZE >> ./logs/Os
./pmm-secuencial-modificadoAOs  $SIZE >> ./logs/Os
./pmm-secuencial-modificadoBOs  $SIZE >> ./logs/Os


paste ./logs/log.0 ./logs/O0 ./logs/O1 ./logs/O2 ./logs/O3 ./logs/Os > ./logs/log_final

cat ./logs/log_final
