#include <iostream>
#include <ctime>
using namespace std;

void multiplicarMatricesPorBloques(int** A, int** B, int** C, int N, int blockSize) {
    for (int iBlock = 0; iBlock < N; iBlock += blockSize) {
        for (int jBlock = 0; jBlock < N; jBlock += blockSize) {
            for (int kBlock = 0; kBlock < N; kBlock += blockSize) {
                // Multiplicación de bloques
                for (int i = iBlock; i < min(iBlock + blockSize, N); i++) {
                    for (int j = jBlock; j < min(jBlock + blockSize, N); j++) {
                        int sum = 0;
                        for (int k = kBlock; k < min(kBlock + blockSize, N); k++) {
                            sum += A[i][k] * B[k][j];
                        }
                        C[i][j] += sum;
                    }
                }
            }
        }
    }
}

void inicializarMatrices(int** matriz, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand() % 10;
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

    int N, blockSize;
    cout << "Ingrese el tamanho de la matriz (N): "; cin >> N;

    cout << "Ingrese el tamanho del bloque: "; cin >> blockSize;

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

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
        }
    }

    clock_t start = clock();
    multiplicarMatricesPorBloques(A, B, C, N, blockSize);
    clock_t end = clock();

    // Calculo el tiempo de ejecución
    double tiempo = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion con multiplicacion por bloques: " << tiempo << " segundos" << endl;

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
