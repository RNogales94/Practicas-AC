#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _OPENMP
#include <omp.h>
#endif

int main(int argc, char **argv){

  int k, j, i;	
  double tiempo;

  int *vector;
  int **matriz;
  int *vector_resultante;
	
  if (argc < 2){
	fprintf(stderr, "\nError --> Falta el número de componentes\n");
	return(-1);
  }

  int m;
  m = atoi(argv[1]);

  if (m > 11000){
	printf("Error --> extensión inadecuada\n");
	return(-1);
  }

  vector = (int *)malloc(m * sizeof(int));
  vector_resultante = (int *)malloc(m * sizeof(int));	
  matriz = (int **)malloc(m * sizeof(int *));
	
  if (matriz == NULL){
	printf("Error de memoria \n");
	free(matriz);
	return -1;
  }
	
  for (i = 0;i < m;i++){
	matriz[i] = (int *)malloc(m * sizeof(int));

	if (matriz[i] == NULL){
		printf("Error de memoria \n");
		return -1;
	}
  }

  #pragma omp parallel for private(i)
  for (j = 0; j < m; j++){
	for (i = 0;i < m;i++){
            matriz[j][i] = j+i;				
	}
	vector[j] = 1;
  }
	
  int suma;

  suma = 0;
  tiempo = omp_get_wtime();
  	
  for (i = 0; i < m; i++){
	suma = 0;
	#pragma omp parallel for reduction(+:suma)
	for (j = 0; j < m; j++){
		suma += (matriz[j][i]*vector[i]);	
	}

  	vector_resultante[i] = suma;
  }
  
  tiempo = omp_get_wtime() - tiempo;

  if (m < 10){
	for (k = 0; k < m; k++){
		printf ("vector_resultante[%d]=%d\n", k, vector_resultante[k]);
	}
  }
  else{
	printf ("vector_resultante[0]=%d\n",vector_resultante[0]);
	printf ("vector_resultante[matriz]=%d\n",vector_resultante[m-1]);
  }

  printf ("El tiempo de ejecución es: %f\n", tiempo);	 
		
}
