#include <iostream>
#include <ctime>
using namespace std;

void multiplicarMatrices(int** A, int** B, int** C, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void inicializarMatrices(int** matriz, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand() % 10;  // Valores entre 0 y 9
        }
    }
}

void imprimirMatriz(int** matriz, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));

    int N;
    cout << "Ingrese el tamaño de la matriz (N): "; cin >> N;

    int** A = new int*[N];
    int** B = new int*[N];
    int** C = new int*[N];

    for (int i = 0; i < N; i++) {
        A[i] = new int[N];
        B[i] = new int[N];
        C[i] = new int[N];
    }

    inicializarMatrices(A, N);
    inicializarMatrices(B, N);

    clock_t start = clock();
    multiplicarMatrices(A, B, C, N);
    clock_t end = clock();

    // Calculo el tiempo de ejecución
    double tiempo = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion: " << tiempo << " segundos" << endl;

    for (int i = 0; i < N; i++) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
