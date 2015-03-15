#!/bin/bash
#Se ejecuta SumaVectorGlobal, que está en el directorio en el que se ha ejecutado el script
#para N potencia de 2 desde 2^16 a 2^26

for ((N=65536;N<67108865;N=N*2))
do
	echo "$N"
   /usr/bin/time -f %E,%U,%S ./SumaVectoresGlobal $N > /dev/null
   #/usr/bin/time -f %E,%U,%S ./SumaVectoresFOR $N > /dev/null

done
