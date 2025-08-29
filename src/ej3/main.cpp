#include <iostream>
#include <iomanip>
#include "matrix_utils.hpp"

int main() {
    try {
        // Crear la matriz original
        Matrix3x3 matriz = crearMatriz3x3();

        // Inicializar con los valores del ejercicio
        inicializarMatriz(matriz);

        std::cout << "=== EJERCICIO 3: HERRAMIENTAS PARA NAVEGACION DE DRONES ===\n";

        std::cout << "\nMatriz original A:\n";
        imprimirMatriz(matriz);

        // Calcular y mostrar el determinante
        double det = calcularDeterminante(matriz);
        std::cout << "Determinante de A: " << std::fixed << std::setprecision(2) << det << "\n";

        // Crear matriz para almacenar la inversa
        Matrix3x3 inversa = crearMatriz3x3();

        // Calcular la matriz inversa
        calcularInversa(matriz, inversa);

        std::cout << "\nMatriz inversa A^(-1):\n";
        imprimirMatriz(inversa);

        std::cout << "Calculo completado exitosamente!\n";

    } catch (const std::runtime_error& e) {
        // Capturamos la excepción si el determinante es cero
        std::cout << "ERROR: " << e.what() << "\n";
        return 1;
    } catch (const std::exception& e) {
        // Capturamos cualquier otra excepción
        std::cout << "ERROR inesperado: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
