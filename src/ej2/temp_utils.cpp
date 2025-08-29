#include "temp_utils.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

std::vector<UniqueTemp> generarLecturas(size_t N, int a, int b) {
    std::vector<UniqueTemp> lecturas;
    lecturas.reserve(N);

    // Establecer semilla
    static bool semilla_establecida = false;
    if (!semilla_establecida) {
        srand(static_cast<unsigned>(time(nullptr)));
        semilla_establecida = true;
    }

    for (size_t i = 0; i < N; ++i) {
        int randomTemp = a + rand() % (b - a + 1);
        lecturas.push_back(std::make_unique<TempValue>(randomTemp));
    }

    return lecturas;
}

void alertaTemperatura(int temperatura, int numeroDron) {
    std::cout << "¡ALERTA! Dron " << numeroDron << " registró " << temperatura << "°C (superó el umbral)\n";
}

void checkTemp(const UniqueTemp& lectura, AlertCallback cb,
               std::vector<SharedTemp>& historial, int numeroDron, int umbral) {
    if (!lectura) {
        return;
    }

    TempValue temp = *lectura;

    // Disparar callback si supera el umbral
    if (temp > umbral) {
        cb(temp, numeroDron);
    }

    // Agregar al historial como shared_ptr
    historial.push_back(std::make_shared<TempValue>(temp));
}

void imprimirLecturas(const std::vector<UniqueTemp>& lecturas) {
    std::cout << "Lecturas de temperatura:\n";
    for (size_t i = 0; i < lecturas.size(); ++i) {
        if (lecturas[i]) {
            std::cout << "  Drone " << (i + 1) << ": " << *lecturas[i] << "°C\n";
        }
    }
}

void imprimirHistorial(const std::vector<SharedTemp>& historial) {
    std::cout << "\nHistorial de temperaturas:\n";
    for (size_t i = 0; i < historial.size(); ++i) {
        if (historial[i]) {
            std::cout << "  Entrada " << (i + 1) << ": " << *historial[i]
                      << "°C (referencias activas: " << historial[i].use_count() << ")\n";
        }
    }
}
