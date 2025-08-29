#ifndef TEMP_UTILS_HPP
#define TEMP_UTILS_HPP

#include <memory>
#include <vector>
#include <functional>

using TempValue = int;
using UniqueTemp = std::unique_ptr<TempValue>;
using SharedTemp = std::shared_ptr<TempValue>;

// Callback para alertas de temperatura
using AlertCallback = std::function<void(int, int)>;

// Genera N lecturas de temperatura con unique_ptr en el rango [a, b]
std::vector<UniqueTemp> generarLecturas(size_t N, int a = 15, int b = 40);

// Callback
void alertaTemperatura(int temperatura, int numeroDron);

// Verifica una lectura, dispara callback si > umbral y la agrega al historial
void checkTemp(const UniqueTemp& lectura, AlertCallback cb,
               std::vector<SharedTemp>& historial, int numeroDron, int umbral = 30);

// Imprime las lecturas actuales
void imprimirLecturas(const std::vector<UniqueTemp>& lecturas);

// Imprime el historial con use_count de cada shared_ptr
void imprimirHistorial(const std::vector<SharedTemp>& historial);

#endif // TEMP_UTILS_HPP
