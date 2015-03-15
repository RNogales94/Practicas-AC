#include <functional>
#include <numeric>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

const int N = 5000, REP = 4000;
default_random_engine generator(N * REP);
uniform_int_distribution<int> distribution(0, 9);
auto rng = bind(distribution, generator);

void daxpy(int* A, int* B, int N, double alpha){
    int i=0;
    for(i=0; i<N; ++i){
        A[i]= alpha*B[i] + A[i];
    }
} 

int main(int argc,char **argv) {
        double tiempo;
        time_t t_inicio, t_final;
        if (argc<2) {
                cout << "Faltan no componentes del vector" <<endl;
                return(-1);
        }
        const int N=atoi(argv[1]);

        //Inicializacion de los datos:
        int *A = new int[N];
        int *B = new int[N];
        int i;
        for(i=0; i<N; ++i){
                A[i] = rng();
                B[i] = rng();
        }
        
        const double alpha = 10.5;

        t_inicio=clock();
        daxpy(A, B, N, alpha);
        t_final=clock();
        tiempo = ((double)(t_final - t_inicio))/CLOCKS_PER_SEC;

        //Imprimir resultado de la suma y el tiempo de ejecución

        if(N<10){
                cout <<"Vector resultado:"<<endl;
                for(i=0; i<N-1; i++) {
                        cout << A[i] << ", ";
                }
                cout <<  A[i] << endl;
        
        cout<<"Tiempo(seg.): "<<tiempo<<" / Tamaño Vectores: "<<N<<endl;
        cout<<"Primer componente del vector resultado ["<<A[0]<<"] y el ultimo componente del vector resultado ["<<A[N-1]<<"]\n";
        }
        else
                cout << tiempo << endl;

        delete [] A;
        delete [] B;
        //Eliminamos la memoria dinamica.
}
