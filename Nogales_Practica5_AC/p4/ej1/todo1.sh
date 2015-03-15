#!/bin/bash
echo "Compilando..."
./compilar.sh struct
echo "struct [OK]"
./compilar.sh struct-modificadoA
echo "modificacin A [OK]"
./compilar.sh struct-modificadoB
echo "modificacin B [OK]"
./compilar.sh struct-modificadoC
echo "modificacin C [OK]"
./compilar.sh struct-modificadoD
echo "modificacin D [OK]"


echo "COMPILACION OK!"
./tabla1.sh
