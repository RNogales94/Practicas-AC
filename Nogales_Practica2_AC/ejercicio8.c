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
  //Indices para cada hebra
  int i, j, k, l;
  //Leer argumento de entrada (nº de componentes del vector)
  if (argc<2){
    printf("Faltan nº componentes del vector\n");
    exit(-1);
  }
  printf("Numero de hebras: %d\n", omp_get_max_threads());

  unsigned int N = atoi(argv[1]);
  printf("N: %s = N:%d\n", argv[1], N);
  #ifdef VECTOR_GLOBAL
  if (N>MAX) N=MAX;
  #endif


  printf("Inicializacion:\n");
  //Inicializar vectores en cuatro partes (Aprovechando 4 hebras)

  #pragma omp parallel sections
  {
	  #pragma omp section
	  {
		  for(i=0; i<N/2; i++){
			 v1[i] = N*0.1+i*0.1;
			 //printf("v1[%d] - Hebra: %d: %f\n",i, omp_get_thread_num(), v1[i]);
		  }
	  }
	  #pragma omp section
	  {
		  for(j=0; j<N/2; j++){
			 v2[j] = N*0.1-j*0.1;
			 //printf("v2[%d] - Hebra: %d: %f\n",j, omp_get_thread_num(), v2[i]);
		  }
	  }
	  #pragma omp section
	  {
		  for(k=N/2; k<N; k++){
			 v1[k] = N*0.1+k*0.1;
			 //printf("v1[%d] - Hebra: %d: %f\n",k, omp_get_thread_num(), v1[k]);
		  }
	  }
	  #pragma omp section
	  {
		  for(l=N/2; l<N; l++){
			 v2[l] = N*0.1-l*0.1;
			 //printf("v2[%d] - Hebra: %d: %f\n",l, omp_get_thread_num(), v2[l]);
		  }
	  }
  }
  //#pragma omp barrier No hace falta ponerla porque sections tiene barrera implicita

  double start = omp_get_wtime();
  //Calcular suma de vectores tambien en 4 hebras aprovechando la arquitectura de mi PC

  printf("Suma:\n");
  #pragma omp parallel sections
  {
	  #pragma omp section
	  {
		  for(i=0; i<N/4; i++){
			 v3[i] = v1[i] + v2[i];
		  }
	  }
	  #pragma omp section
	  {
		  for(j=N/4; j<N/2; j++){
			 v3[j] = v1[j] + v2[j];
		  }
	  }
	  #pragma omp section
	  {
		  for(k=N/2; k<3*N/4; k++){
			 v3[k] = v1[k] + v2[k];
		  }
	  }
	  #pragma omp section
	  {
		  for(l=3*N/4; l<N; l++){
			 v3[l] = v1[l] + v2[l];
		  }
	  }
  }

 double end = omp_get_wtime();
 double time = end - start;


  //Imprimir resultado de la suma y el tiempo de ejecución
  printf("Tiempo(seg.):%11.9f\n / Tamaño Vectores:%u\n/ V1[0]+V2[0]=V3[0](%8.6f+%8.6f=%8.6f)\n V1[%d]+V2[%d]=V3[%d](%8.6f+%8.6f=%8.6f) /\n", time,N,v1[0],v2[0],v3[0],N-1,N-1,N-1,v1[N-1],v2[N-1],v3[N-1]); 

 if (N < 50){
   for(i=0; i<N; i++){
     printf("v1[%d] + v2[%d] = v3[%d]\t %f + %f = %f\n",i,i,i, v1[i], v2[i], v3[i]);
   }
 }

  return 0;
}
