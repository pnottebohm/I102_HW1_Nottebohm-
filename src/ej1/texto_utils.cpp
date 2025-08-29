#include "texto_utils.hpp"

size_t contarReemplazar(std::string& texto,
                        const std::string& objetivo,
                        const std::string& reemplazo) {
    size_t cantidad_reemplazos = 0;

    if (objetivo.size() == 0) {
        return 0;
    }

    size_t pos = 0;
    while (true) {
        pos = texto.find(objetivo, pos);

        if (pos == std::string::npos) break; // No encuentra más coincidencias

        texto.replace(pos, objetivo.size(), reemplazo);
        cantidad_reemplazos++;
        pos += reemplazo.size();
    }

    return cantidad_reemplazos;
}
