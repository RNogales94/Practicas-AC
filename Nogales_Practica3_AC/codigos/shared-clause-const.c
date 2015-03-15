#include <stdio.h>
#ifdef _OPENMP
  #include <omp.h>
#endif

main(){
   const int n=7;
   int i;
   int a[n];

   for (i=0; i<n; i++)
      a[i] = i+1;

   #pragma omp parallel for default(none) shared(a)
   for (i=0; i<n; i++)    a[i] += i;

   printf("Después de parallel for:\n");

   for (i=0; i<n; i++)
      printf("a[%d] = %d\n",i,a[i]);
}