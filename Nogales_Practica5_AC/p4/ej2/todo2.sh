#!/bin/bash
echo "Compilando..."
./compilar.sh pmm-secuencial
echo "secuencial [OK]"
./compilar.sh pmm-secuencial-modificadoA
echo "modificacin A [OK]"
./compilar.sh pmm-secuencial-modificadoB
echo "modificacin B [OK]"

echo "COMPILACION OK!"
./tabla2.sh 500
