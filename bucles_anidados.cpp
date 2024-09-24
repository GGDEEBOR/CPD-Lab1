#include <iostream>
#include <chrono>
using namespace std;

const int MAX = 10000; 

double A[MAX][MAX];
double x[MAX], y[MAX];

void initializeArrays() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            A[i][j] = i + j;
        }
        x[i] = i;
        y[i] = 0;
    }
}

void rowMajorOrder() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

void columnMajorOrder() {
    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

int main() {
    initializeArrays();

    auto start1 = chrono::high_resolution_clock::now();
    rowMajorOrder();
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed1 = end1 - start1;
    cout << "Tiempo de ejecucion para row-major order: " << elapsed1.count() << " segundos" << endl;

    // Reinicia el arreglo y antes de ejecutar el segundo bucle
    for (int i = 0; i < MAX; i++) {
        y[i] = 0;
    }

    auto start2 = chrono::high_resolution_clock::now();
    columnMajorOrder();
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed2 = end2 - start2;
    cout << "Tiempo de ejecucion para column-major order: " << elapsed2.count() << " segundos" << endl;

    return 0;
}
