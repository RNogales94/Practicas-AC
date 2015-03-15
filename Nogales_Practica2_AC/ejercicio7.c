/* SumaVectoresC.c
 Suma de dos vectores: v3 = v1 + v2

 Para compilar usar (-lrt: real time library):
	gcc  -O2 SumaVectores.c -o SumaVectores -lrt

 Para ejecutar use: SumaVectoresC longitud
*/

#include <stdlib.h>	// biblioteca con funciones atoi(), malloc() y free()
#include <stdio.h>   // biblioteca donde se encuentra la función printf()
#include <time.h>	   // biblioteca donde se encuentra la función clock_gettime()
#include <omp.h> 	   // biblioteca openmp

#define VECTOR_GLOBAL

#ifdef VECTOR_GLOBAL
#define MAX 33554432	  //=2^25
double v1[MAX], v2[MAX], v3[MAX];
#endif

int main(int argc, char** argv){

  int i;
  //Leer argumento de entrada (nº de componentes del vector)
  if (argc<2){
    printf("Faltan nº componentes del vector\n");
    exit(-1);
  }
  //printf("Numero de hebras: %d\n", omp_get_max_threads());

  unsigned int N = atoi(argv[1]);
  printf("N: %s = N:%d\n", argv[1], N);
  #ifdef VECTOR_GLOBAL
  if (N>MAX) N=MAX;
  #endif

  #pragma omp parallel
  {
  	 #pragma omp for
	 for(i=0; i<N; i++){
	 	v1[i] = N*0.1+i*0.1;
	 	v2[i] = N*0.1-i*0.1;
	 }
  }

  double start = omp_get_wtime();
  //Calcular suma de vectores tambien en 4 hebras aprovechando la arquitectura de mi PC

  #pragma omp parallel
  {
	#pragma omp for
	for(i=0; i<N; i++){
		v3[i] = v1[i] + v2[i];
	}
  }

 double end = omp_get_wtime();
 double time = end - start;


  //Imprimir resultado de la suma y el tiempo de ejecución
    printf("Tiempo(seg.):%11.9f\n / Tamaño Vectores:%u\n/ V1[0]+V2[0]=V3[0](%8.6f+%8.6f=%8.6f)\n V1[%d]+V2[%d]=V3[%d](%8.6f+%8.6f=%8.6f) /\n", time,N,v1[0],v2[0],v3[0],N-1,N-1,N-1,v1[N-1],v2[N-1],v3[N-1]);

 if (N < 50){
 	for(i=0; i<N; i++){
 		printf("%f + %f = %f\n",v1[i], v2[i], v3[i]);
 	}
 }


  return 0;
}
