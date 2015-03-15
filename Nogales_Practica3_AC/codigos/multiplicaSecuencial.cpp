#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int ** ReservaMatriz(int dim)
{
    int **M;
    if (dim  <= 0)
    {
        cerr<< "\n ERROR: Dimension de la matriz debe ser mayor que 0" << endl;
        exit(1);
    }
    M = new int* [dim];
    if (M == NULL)
    {
        cerr << "\n ERROR: No puedo reservar memoria para un matriz de "
        << dim << " x " << dim << "elementos" << endl;
        exit(1);
    }
    for (int i = 0; i < dim; i++)
    {
        M[i]= new int [dim];
        if (M[i] == NULL)
        {
            cerr << "ERROR: No puedo reservar memoria para un matriz de "
            << dim << " x " << dim << endl;
            for (int j = 0; j < i; j++)
                delete [] M[i];
            delete [] M;
            exit(1);
        } 
    }
    return M;
}


void LiberaMatriz(int ** & M, int dim)
{
    for (int i = 0; i < dim; i++)
        delete [] M[i];
    delete [] M;
    M = NULL;
}
void LiberaVector(int * & V)
{
    delete [] V;
    V = NULL;
}


void MultiplicarMatrices(int** & Matriz, int* & vector, int* & resultado, int dim){
    for(int i=0; i<dim; i++){
        resultado[i]=0;
        for(int j=0; j<dim; j++){
            resultado[i] += Matriz[i][j] * vector[j];
        }
    }
}

void ImprimirProducto(int** & matriz, int* & vector, int* & vector_resultante, int dim){
    for(int i=0; i<dim; i++){
        for(int j=-1; j<dim+6; j++){
            if(j==-1){
                cout << "( ";
            }
            if(0<=j && j<dim){
                cout << matriz[i][j] << " ";
            }
            else if(j==dim){
                cout << ") (";
            }
            else if(j==dim+1){
                cout << vector[i];
            }
            else if(j==dim+2){
                cout << ") ";
            }
            else if(j==dim+3){
                if(i == dim/2){
                    cout << " = (";
                }
                else
                    cout << "   (";
            }
            else if(j==dim+4){
                cout << vector_resultante[i];
            }
            else if(j==dim+5){
                cout << ")";
            }
        }
        cout << endl;
    }
}


int main(int argc, char **argv){
    int N;
    clock_t tantes;    // Valor del reloj antes de la ejecucion
    clock_t tdespues;  // Valor del reloj despues de la ejecucion
	 
	if(argc < 2){
      cerr << "Falta iteraciones" << endl;
      return(-1);
    }
    N = atoi(argv[1]); 

    //Reserva de memoria para los vectores(N) y la matriz(NxN)
    int * vector = new int[N];
    int * vector_resultante = new int[N];
    int ** matriz = ReservaMatriz(N);
    //Inicializar vector
    for (int i=0; i < N; i++){
        vector[i] = 1;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            matriz[i][j] = i+j;
        }
    }
    //int suma=0;
    tantes = clock();
    MultiplicarMatrices(matriz, vector, vector_resultante, N);
    tdespues = clock();
    if(N<10){
        ImprimirProducto(matriz, vector, vector_resultante, N);
        cout << endl;
    }
    cout <<"Tiempo: " << ((double)(tdespues-tantes))/CLOCKS_PER_SEC << " s" << endl;
    LiberaMatriz(matriz,N);
    LiberaVector(vector);
    LiberaVector(vector_resultante);
}
