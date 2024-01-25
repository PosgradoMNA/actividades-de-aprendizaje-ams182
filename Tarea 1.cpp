#include <iostream>
#include <omp.h>

const int N = 1000;

int main() {
    // Creando los arreglos que serán las variables
    int A[N], B[N], result[N];

    // Se llenan los arreglos con valores aleatorios
    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        A[i] = rand() % 100;
        B[i] = rand() % 100;
    }

    // Ssuma en paralelo
    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        result[i] = A[i] + B[i];
    }

    // Imprimir parte de los arreglos
    std::cout << "A: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << A[i] << " ";
    }

    std::cout << "\nB: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << B[i] << " ";
    }

    std::cout << "\nResultado: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << result[i] << " ";
    }

    return 0;
}
