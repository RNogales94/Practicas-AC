#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
  #include <omp.h>
#else
   #define omp_get_thread_num() 0
#endif

int main(int argc, char **argv) { 
   int i, n=16,chunk,a[n],suma=0;
   if(argc < 2)     {
      fprintf(stderr,"\nFalta chunk (3)\n");
      exit(-1);
     }
   chunk = atoi(argv[1]);
   printf("Chunk %d\n",chunk);
   for (i=0; i<n; i++)      a[i] = i; 
 
   #pragma omp parallel for num_threads(2) firstprivate(suma) \
                 lastprivate(suma)  schedule(guided,chunk)
   for (i=0; i<n; i++)
   {   suma = suma + a[i];
       printf("%d\n",omp_get_thread_num());
   }    
   //printf("Fuera de 'parallel for' suma=%d\n",suma);

   return(0);
}