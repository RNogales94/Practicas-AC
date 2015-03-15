#!/bin/bash
echo "Compilando..."
./compilar.sh daxpy
echo "daxpy [OK]"

echo "COMPILACION OK!"
 ./desensablar.sh
echo "DESENSAMBLADO OK!"
