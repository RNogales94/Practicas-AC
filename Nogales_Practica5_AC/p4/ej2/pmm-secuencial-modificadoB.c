#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 4096

int main(int argc, char **argv){
	int i, j, k, h;
	int dimension_matrices;
	int suma = 0; int s1,s2,s3,s4,s5,s6,s7,s8;
        s1=s2=s3=s4=s5=s6=s7=s8=0;
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
			s1=0; s2=0; s3=0; s4=0;
                        s5=0; s6=0; s7=0; s8=0;
			for (h=0, k=0;h < rondas_bucle_interno; ++h, k+=8){
			        s1 += (matrizB[i][k]*matrizC[k][j]);
                                s2 += (matrizB[i][k+1]*matrizC[j][k+1]);
                                s3 += (matrizB[i][k+2]*matrizC[j][k+2]);
                                s4 += (matrizB[i][k+3]*matrizC[j][k+3]);
                                s5 += (matrizB[i][k+4]*matrizC[j][k+4]);
                                s6 += (matrizB[i][k+5]*matrizC[j][k+5]);
                                s7 += (matrizB[i][k+6]*matrizC[j][k+6]);
                                s8 += (matrizB[i][k+7]*matrizC[j][k+7]);
		        }
                        suma= s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8;
		        matrizA[i][j]=suma;
                        for(k=rondas_bucle_interno*8; k<dimension_matrices; ++k){
			        suma += (matrizB[i][k]*matrizC[j][k]);
                        }
                        matrizA[i][j]=suma;
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

