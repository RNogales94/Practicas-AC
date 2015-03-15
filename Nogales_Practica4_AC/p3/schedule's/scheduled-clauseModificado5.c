#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
  #include <omp.h>
#else
   #define omp_get_thread_num() 0
#endif

int main(int argc, char **argv) { 
	int i, n=200,chunk,a[n],suma=0;
	int * modifier;
	omp_sched_t * kind;
		
   if(argc < 3)     {
      fprintf(stderr,"\nFalta iteraciones o chunk \n");
      exit(-1);
     }
   n = atoi(argv[1]); if (n>200) n=200; chunk = atoi(argv[2]); 

   for (i=0; i<n; i++)       a[i] = i; 

	#pragma omp parallel
	{
		#pragma omp single
 		{
			printf("[Parallel] dyn-var: %d \n",omp_get_dynamic());
			printf("[Parallel] Modificamos dyn-var: (hacemos omp_set_dynamic(3);) \n");
			omp_set_dynamic(3);
			printf("[Parallel] dyn-var despues de la modificacion: %d \n",omp_get_dynamic());

			printf("[Parallel] nthreads-var: %d \n",omp_get_max_threads());
			printf("[Parallel] Modificar nthreads-var: (lo ponemos a 8) \n");
			omp_set_num_threads(8);
			printf("[Parallel] nthreads-var despues de la modificacion: %d \n",omp_get_max_threads);

			omp_get_schedule(&kind,&modifier);
			printf("[Parallel] run-sched-var: (Kind: %d, Modifier: %d) \n",kind,modifier);
			printf("[Parallel] Modificar run-sched-var: \n");
			omp_set_schedule(3,2);
			omp_get_schedule(&kind,&modifier);
			printf("[Parallel] Kind despues la modificacion: %d, Modifier despues la modificacion: %d \n",kind,modifier);

		}
		
		#pragma omp barrier
   	#pragma omp for firstprivate(suma) \
            lastprivate(suma) schedule(dynamic,chunk)
		for (i=0; i<n; i++){
			suma = suma + a[i];
			printf(" thread %d suma a[%d]=%d suma=%d \n", omp_get_thread_num(),i,a[i],suma);
		}
	}  
  
   printf("[Fuera Parallel] suma=%d\n",suma); 
	printf("[Fuera Parallel] dyn-var: %d \n",omp_get_dynamic());
	printf("[Fuera Parallel] nthreads-var: %d \n",omp_get_max_threads());
	omp_get_schedule(&kind,&modifier);
	printf("[Fuera Parallel] run-sched-var: (Kind: %d. Modifier: %d) \n",kind,modifier);

   return(0);
}

