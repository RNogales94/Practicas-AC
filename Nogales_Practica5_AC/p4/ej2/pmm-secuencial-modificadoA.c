#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 4096

int main(int argc, char **argv){
	int i, j, k, h;
	int dimension_matrices;
	int suma = 0; int suma2 = 0;
        time_t t_inicio, t_final;
        double tiempo;

	int **matrizB;
	int **matrizC;
	int **matrizA;

	if (argc < 2){
		printf("Falta el número de componentes\n");
		return(1);
	}

    //El producto de matrices cuadradas requiere que ambas sean de la misma
    //dimension por tanto solo necesitamos un parametro para reservar la memoria
	dimension_matrices = atoi(argv[1]);

	if (dimension_matrices > MAX){
		printf("Tamaño demasiado grande. No superar %d\n\n",MAX);
		return(1);
	}

//Creamos las matrices
// matrizA = matrizB * matrizC

	matrizB = (int **)malloc(dimension_matrices * sizeof(int*));
	matrizC = (int **)malloc(dimension_matrices * sizeof(int*));
	matrizA = (int **)malloc(dimension_matrices * sizeof(int*));

	for (i=0; i<dimension_matrices; i++){
		matrizB[i] = (int *)malloc(dimension_matrices * sizeof(int));
		matrizC[i] = (int *)malloc(dimension_matrices * sizeof(int));
		matrizA[i] = (int *)malloc(dimension_matrices * sizeof(int));
	}

//Inicializamos las matrices
	for (j=0; j<dimension_matrices; ++j){
		for (i=0; i<dimension_matrices; i++){
			matrizB[j][i] = j+i;
			matrizC[j][i] = j*i;
		}
	}

        t_inicio=clock();
//Multiplicamos las matrices B y C
        int rondas_bucle_interno = dimension_matrices/8; // 8 = cte_desenrollado
        //printf("Rondas internas %d\n",rondas_bucle_interno);
	for (i=0; i<dimension_matrices; i++){
		for(j=0; j<dimension_matrices; j++){
			suma = 0;
                        suma2 = 0;
			for (h=0, k=0;h < rondas_bucle_interno; ++h, k+=8){
			        suma += (matrizB[i][k]*matrizC[k][j]);
                                suma += (matrizB[i][k+1]*matrizC[k+1][j]);
                                suma += (matrizB[i][k+2]*matrizC[k+2][j]);
                                suma += (matrizB[i][k+3]*matrizC[k+3][j]);
                                suma2 += (matrizB[i][k+4]*matrizC[k+4][j]);
                                suma2 += (matrizB[i][k+5]*matrizC[k+5][j]);
                                suma2 += (matrizB[i][k+6]*matrizC[k+6][j]);
                                suma2 += (matrizB[i][k+7]*matrizC[k+7][j]);
		        }
		        matrizA[i][j]=suma + suma2;
                        for(k=rondas_bucle_interno*8; k<dimension_matrices; ++k){
			        suma += (matrizB[i][k]*matrizC[k][j]);
                        }
                        matrizA[i][j]=suma + suma2;
		}
	}

//Imprimimos resultados
        t_final=clock();
        tiempo = ((double)(t_final - t_inicio))/CLOCKS_PER_SEC;
        printf ("%f\n",tiempo);
	//printf ("Resultado[0][0] = %d\n",matrizA[0][0]);
	//printf ("Componente(N-1,N-1) del resultado de la multiplicación de ambas matrices=%d\n",matrizA[dimension_matrices-1][dimension_matrices-1]);

//Liberamos las matrices
    free(matrizA);
    free(matrizB);
    free(matrizC);

    return 0;
}

