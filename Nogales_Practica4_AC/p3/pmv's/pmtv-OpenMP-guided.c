#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define MAX 11000

int main(int argc, char **argv){
	
	int i, j;
	int filas_columnas;
	double tiempo;
	int suma;
	suma = 0;

	int *vector;
	int **matriz;
	int *resultado;

	int chunk;

	if (argc < 2){
       printf("Falta chunk y número de componentes\n");
	   return(-1);
	}

	if(argc < 3)     {
		printf("Falta chunk\n");
        return(-1);
    }
    
    chunk = atoi(argv[2]);
    
    //El número de filas y columnas será un argumento de entrada
    //Al ser una matriz triangular, sabemos que es cuadrado (no filas = no columnas)
    
    filas_columnas = atoi(argv[1]);
    
	if (filas_columnas > MAX){
		printf("Tamaño demasiado grande. Superar %d produce errores\n",MAX);
		return(-1);
	}

    //Reservamos la matriz, el vector, y el resultado de la multiplicacion

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

	//Multiplicamos la matriz por el vector(paralelizamos)
	tiempo = omp_get_wtime();
	#pragma omp parallel for private(suma) schedule(guided,chunk)
	for (i=0; i<filas_columnas; i++){
		suma=0;
		for (j=0; j<filas_columnas; j++){
			suma+=(matriz[j][i]*vector[i]);
		}
		resultado[i] = suma;
	}
	tiempo = omp_get_wtime() - tiempo;
	 if(argc == 3){
	        printf ("El tiempo de ejecucion es: %f\n", tiempo);
	
	        printf ("Componente(0,0) del resultado del producto: matriz triangular por vector = %d \n",resultado[0]);
	        printf ("Componente(N-1,N-1) del resultado del producto: matriz triangular por vector = %d \n",resultado[filas_columnas-1]);
        }
        else //version para script
            printf ("%f\n", tiempo);   
    //Liberamos la memoria
    free(matriz);
    free(resultado);
    free(vector);

    return 0;
}


