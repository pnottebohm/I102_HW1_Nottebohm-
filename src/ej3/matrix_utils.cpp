#include "matrix_utils.hpp"
#include <iostream>
#include <stdexcept>
#include <iomanip>

// Función para crear una matriz 3x3 vacía
Matrix3x3 crearMatriz3x3() {
    Matrix3x3 matriz = std::make_unique<std::unique_ptr<double[]>[]>(3);
    for (int i = 0; i < 3; i++) {
        matriz[i] = std::make_unique<double[]>(3);
    }
    return matriz;
}

// Función para inicializar la matriz con los valores dados en la consigna
void inicializarMatriz(Matrix3x3& matriz) {

    matriz[0][0] = 2;  matriz[0][1] = -1; matriz[0][2] = 0;
    matriz[1][0] = 0;  matriz[1][1] = 2;  matriz[1][2] = 1;
    matriz[2][0] = 0;  matriz[2][1] = 0;  matriz[2][2] = 1;
}

// Función para calcular el determinante de una matriz 3x3
double calcularDeterminante(const Matrix3x3& matriz) {
    double det = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1])
               - matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0])
               + matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);

    return det;
}

// Función para calcular la matriz inversa
void calcularInversa(const Matrix3x3& matriz, Matrix3x3& inv) {
    double det = calcularDeterminante(matriz);

    // Si el determinante es cero, no se puede calcular la inversa
    if (det == 0.0) {
        throw std::runtime_error("Error: La matriz no tiene inversa porque su determinante es cero");
    }

    // Calculamos los cofactores
    double c00 = matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1];
    double c01 = -(matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0]);
    double c02 = matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0];
    double c10 = -(matriz[0][1] * matriz[2][2] - matriz[0][2] * matriz[2][1]);
    double c11 = matriz[0][0] * matriz[2][2] - matriz[0][2] * matriz[2][0];
    double c12 = -(matriz[0][0] * matriz[2][1] - matriz[0][1] * matriz[2][0]);
    double c20 = matriz[0][1] * matriz[1][2] - matriz[0][2] * matriz[1][1];
    double c21 = -(matriz[0][0] * matriz[1][2] - matriz[0][2] * matriz[1][0]);
    double c22 = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];

    // La matriz inversa es la transpuesta de cofactores dividida por el determinante
    inv[0][0] = c00 / det;  inv[0][1] = c10 / det;  inv[0][2] = c20 / det;
    inv[1][0] = c01 / det;  inv[1][1] = c11 / det;  inv[1][2] = c21 / det;
    inv[2][0] = c02 / det;  inv[2][1] = c12 / det;  inv[2][2] = c22 / det;
}

// Función para imprimir la matriz por pantalla
void imprimirMatriz(const Matrix3x3& matriz) {
    std::cout << "Matriz:\n";
    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < 3; i++) {
        std::cout << "[ ";
        for (int j = 0; j < 3; j++) {
            std::cout << std::setw(8) << matriz[i][j];
            if (j < 2) std::cout << "  ";
        }
        std::cout << " ]\n";
    }
    std::cout << "\n";
}
