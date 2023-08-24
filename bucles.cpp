#include <iostream>
#include <chrono>
#define MAX 1000

int main() {
    double A[MAX][MAX], x[MAX], y[MAX]; 
    int i, j; 

    std::cout << "Hello World!\n";

    // Inicialización de los arrays y
    for (i = 0; i < MAX; i++) {
        y[i] = 0.0;
    }

    // Medir el tiempo para el primer bucle
    auto time1 = std::chrono::high_resolution_clock::now();

    // Primer bucle
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j];
        }
    }

    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed1 = end1 - time1;

    // Medir el tiempo para el segundo bucle
    auto time2 = std::chrono::high_resolution_clock::now();

    // Segundo bucle
    for (j = 0; j < MAX; j++) {
        for (i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j];
        }
    }

    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = end2 - time2;

    // Comparación de tiempos
    std::cout << "Tiempo para el primer bucle: " << elapsed1.count() << " segundos" << std::endl;
    std::cout << "Tiempo para el segundo bucle: " << elapsed2.count() << " segundos" << std::endl;

    return 0;
}
