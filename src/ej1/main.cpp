#include <iostream>
#include "texto_utils.hpp"

int main() {
    std::cout << "=== EJERCICIO 1: Procesamiento de Variables String ===\n";

    // | Caso del enunciado |
    std::string texto = "hola mundo! hola a todos! Ya dije 'hola' ?";
    std::string objetivo = "hola";
    std::string reemplazo = "ciao";

    std::cout << "Texto original: " << texto << "\n";
    std::cout << "Objetivo: " << objetivo << "\n";
    std::cout << "Reemplazo: " << reemplazo << "\n";

    // Realizar reemplazo con función original
    size_t cantidad = contarReemplazar(texto, objetivo, reemplazo);

    std::cout << "Texto modificado: " << texto << "\n";
    std::cout << "Cantidad de reemplazos realizados: " << cantidad << "\n";

    // | Testeo manual |
    std::cout << "=== TESTEO MANUAL ===\n";
    std::cout << "Ingresa tus propios valores para probar las funciones:\n";

    std::string textoManual, objetivoManual, reemplazoManual;

    std::cout << "Ingresa el texto: ";
    std::cin >> textoManual;

    std::cout << "Ingresa la palabra a buscar: ";
    std::cin >> objetivoManual;

    std::cout << "Ingresa la palabra de reemplazo: ";
    std::cin >> reemplazoManual;

    std::cout << "\nTexto original: " << textoManual << "\n";
    std::cout << "Buscando: " << objetivoManual << "\n";
    std::cout << "Reemplazando por: " << reemplazoManual << "\n";

    // Realizar reemplazo
    size_t cantidadManual = contarReemplazar(textoManual, objetivoManual, reemplazoManual);

    std::cout << "Texto modificado: " << textoManual << "\n";
    std::cout << "Cantidad de reemplazos realizados: " << cantidadManual << "\n";

    std::cout << "\n";

    // | Casos borde |
    std::cout << "=== CASOS BORDE ===\n";

    // Caso 1: objetivo no aparece
    std::string texto3 = "Este texto no contiene la palabra buscada";
    std::string objetivo2 = "xyz";
    std::string reemplazo2 = "abc";

    std::cout << "Caso 1 - Objetivo no aparece:\n";
    std::cout << "Texto: " << texto3 << "\n";
    size_t cantidad3 = contarReemplazar(texto3, objetivo2, reemplazo2);
    std::cout << "Reemplazos: " << cantidad3 << "\n";

    // Caso 2: texto vacío
    std::string textoVacio = "";
    std::cout << "Caso 2 - Texto vacío:\n";
    size_t cantidadVacio = contarReemplazar(textoVacio, "test", "prueba");
    std::cout << "Reemplazos: " << cantidadVacio << "\n";

    // Caso 3: objetivo vacío
    std::string texto4 = "texto de prueba";
    std::cout << "Caso 3 - Objetivo vacío:\n";
    size_t cantidad4 = contarReemplazar(texto4, "", "reemplazo");
    std::cout << "Reemplazos: " << cantidad4 << "\n";
    std::cout << "Texto sin cambios: " << texto4 << "\n";

    // Caso 4: objetivo == reemplazo
    std::string texto5 = "test test test";
    std::cout << "Caso 4 - Objetivo igual a reemplazo:\n";
    std::cout << "Texto original: " << texto5 << "\n";
    size_t cantidad5 = contarReemplazar(texto5, "test", "test");
    std::cout << "Reemplazos: " << cantidad5 << "\n";
    std::cout << "Texto final: " << texto5 << "\n";

    // Caso 5: reemplazo contiene objetivo (evitar loop infinito)
    std::string texto6 = "abc abc abc";
    std::cout << "Caso 5 - Reemplazo contiene objetivo:\n";
    std::cout << "Texto original: " << texto6 << "\n";
    size_t cantidad6 = contarReemplazar(texto6, "abc", "abcdef");
    std::cout << "Reemplazos: " << cantidad6 << "\n";
    std::cout << "Texto final: " << texto6 << "\n";

    // Caso 6: objetivo de un solo carácter
    std::string texto7 = "a.a.a.a";
    std::cout << "Caso 6 - Objetivo de un carácter:\n";
    std::cout << "Texto original: " << texto7 << "\n";
    size_t cantidad7 = contarReemplazar(texto7, "a", "X");
    std::cout << "Reemplazos: " << cantidad7 << "\n";
    std::cout << "Texto final: " << texto7 << "\n";

    // Caso 7: texto muy largo (stress test)
    std::string texto8 = "";
    for (int i = 0; i < 1000; ++i) {
        texto8 += "palabra ";
    }
    std::cout << "Caso 7 - Stress test (texto largo):\n";
    std::cout << "Texto de " << texto8.length() << " caracteres con 1000 repeticiones\n";
    size_t cantidad8 = contarReemplazar(texto8, "palabra", "término");
    std::cout << "Reemplazos: " << cantidad8 << "\n";

    // Caso 8: caracteres especiales
    std::string texto9 = "¡Hola! ¿Cómo estás? ñ á é í ó ú";
    std::cout << "Caso 8 - Caracteres especiales:\n";
    std::cout << "Texto original: " << texto9 << "\n";
    size_t cantidad9 = contarReemplazar(texto9, "á", "a");
    std::cout << "Reemplazos: " << cantidad9 << "\n";
    std::cout << "Texto final: " << texto9 << "\n";

    return 0;
}
