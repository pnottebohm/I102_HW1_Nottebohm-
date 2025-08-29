#include <iostream>
#include "temp_utils.hpp"

int main() {
    std::cout << "=== EJERCICIO 2: Sistema de Notificaciones de Temperatura ===\n";
    std::cout << "Simulando mediciones de 5 drones en diferentes posiciones estratégicas:\n";
    std::cout << "(Base, Media altura, Cumbre, Lado norte, Lado sur)\n";

    // Generar 5 lecturas de temperatura para los drones
    const size_t NUM_DRONES = 5;
    const int min_temp = 15;
    const int max_temp = 40;
    auto lecturas = generarLecturas(NUM_DRONES, min_temp, max_temp);

    // Imprimir las lecturas individuales
    imprimirLecturas(lecturas);

    std::cout << "\nVerificando lecturas (umbral: 30°C)...\n";

    // Historial para almacenar con shared_ptr
    std::vector<SharedTemp> historial;

    // Procesar cada lectura
    for (size_t i = 0; i < lecturas.size(); i++) {
        auto& lectura = lecturas[i];
        checkTemp(lectura, alertaTemperatura, historial, i + 1, 30);
    }

    // Mostrar el historial completo
    imprimirHistorial(historial);

    return 0;
}
