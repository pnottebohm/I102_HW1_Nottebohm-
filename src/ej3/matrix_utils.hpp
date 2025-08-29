#ifndef MATRIX_UTILS_HPP
#define MATRIX_UTILS_HPP

#include <memory>

// Definimos el tipo de matriz 3x3 usando unique_ptr como pide la consigna
using Matrix3x3 = std::unique_ptr<std::unique_ptr<double[]>[]>;

// Función para crear una matriz 3x3 vacía
Matrix3x3 crearMatriz3x3();

// Función para inicializar la matriz con los valores dados en la consigna
void inicializarMatriz(Matrix3x3& matriz);

// Función para calcular el determinante de una matriz 3x3
double calcularDeterminante(const Matrix3x3& matriz);

// Función para calcular la matriz inversa
void calcularInversa(const Matrix3x3& matriz, Matrix3x3& inv);

// Función para imprimir la matriz por pantalla
void imprimirMatriz(const Matrix3x3& matriz);

#endif
