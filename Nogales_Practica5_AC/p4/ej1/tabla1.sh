#!/bin/bash


echo "Modificación  - - - - " > ./logs/log.0 
echo "Sin Modificar - - - - " >> ./logs/log.0
echo "Quitando saltos - - - " >> ./logs/log.0
echo "Precaptacion  - - - - " >> ./logs/log.0
echo "Ambas modificaciones  " >> ./logs/log.0
echo "Modificando el struct " >> ./logs/log.0


echo "   O0    " > ./logs/O0
./structO0 >> ./logs/O0
./struct-modificadoAO0 >> ./logs/O0
./struct-modificadoBO0 >> ./logs/O0
./struct-modificadoCO0 >> ./logs/O0
./struct-modificadoDO0 >> ./logs/O0


echo "   O1    " > ./logs/O1
./structO1 >> ./logs/O1
./struct-modificadoAO1 >> ./logs/O1
./struct-modificadoBO1 >> ./logs/O1
./struct-modificadoCO1 >> ./logs/O1
./struct-modificadoDO1 >> ./logs/O1

echo "   O2    " > ./logs/O2
./structO2 >> ./logs/O2
./struct-modificadoAO2 >> ./logs/O2
./struct-modificadoBO2 >> ./logs/O2
./struct-modificadoCO2 >> ./logs/O2
./struct-modificadoDO2 >> ./logs/O2


echo "  O3    " > ./logs/O3
./structO3 >> ./logs/O3
./struct-modificadoAO3 >> ./logs/O3
./struct-modificadoBO3 >> ./logs/O3
./struct-modificadoCO3 >> ./logs/O3
./struct-modificadoDO3 >> ./logs/O3


echo "   Os    " > ./logs/Os
./structOs >> ./logs/Os
./struct-modificadoAOs >> ./logs/Os
./struct-modificadoBOs >> ./logs/Os
./struct-modificadoCOs >> ./logs/Os
./struct-modificadoDOs >> ./logs/Os


paste ./logs/log.0 ./logs/O0 ./logs/O1 ./logs/O2 ./logs/O3 ./logs/Os > ./logs/log_final

cat ./logs/log_final
