#ifndef TEXTO_UTILS_HPP
#define TEXTO_UTILS_HPP

#include <string>

// Cuenta y reemplaza todas las apariciones de 'objetivo' por 'reemplazo' en 'texto'
// Retorna la cantidad de reemplazos realizados
size_t contarReemplazar(std::string& texto,
                        const std::string& objetivo,
                        const std::string& reemplazo);

#endif // TEXTO_UTILS_HPP
