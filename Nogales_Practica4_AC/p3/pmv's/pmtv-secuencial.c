#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 11000

int main(int argc, char **argv){
	int i, j;
	int filas_columnas;
	int suma;
	suma = 0;

	int *vector;
	int **matriz;
	int *resultado;

	if (argc < 2){
		printf("Falta el número de componentes\n");
		return(-1);
	}
	filas_columnas = atoi(argv[1]);

	if (filas_columnas > MAX){
		printf("Tamaño de la matriz demasiado grande. Superar %d provoca fallos\n",MAX);
		return(-1);
	}
    
    //Reservamos memoria para los vectores y la matriz
	vector = (int *)malloc(filas_columnas * sizeof(int));
	resultado = (int *)malloc(filas_columnas * sizeof(int));
	matriz = (int **)malloc(filas_columnas * sizeof(int *));

	for (i=0; i<filas_columnas; i++){
		matriz[i] = (int *)malloc(filas_columnas * sizeof(int));
	}

//Inicializamos matriz (TRIANGULAR INFERIOR) y vector
// i= columnas de la matriz
// j= filas de la matriz

	for (j=0; j<filas_columnas; j++){
		for (i=0; i<filas_columnas;i++){
			if (j>i)
				matriz[j][i] = 0;
			else
				matriz[j][i] = j*i;
		}
		vector[j] = i;
	}

//Multiplicamos la matriz por el vector
	for (i=0; i<filas_columnas; i++){
		suma=0;
		for (j=0; j<filas_columnas; j++){
			suma+=(matriz[j][i]*vector[i]);
		}
		resultado[i] = suma;
	}
//Hacemos un par de printf para que el optimizador de codigo no se salte el programa entero...
	printf ("Componente(0,0) del resultado del producto: matriz triangular por vector = %d\n",resultado[0]);
	printf ("Componente(N-1,N-1) del resultado del producto: matriz triangular por vector = %d\n",resultado[filas_columnas-1]);
    free(matriz);
    free(resultado);
    free(vector);

    return 0;
}

