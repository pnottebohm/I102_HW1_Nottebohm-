# I102_HW1_Nottebohm-
## Compilación y Ejecución

### Crear directorio bin
mkdir -p bin

### Compilar ejercicios 
# Ejercicio 1
g++ -Wall -Wextra -Wpedantic -O2 -std=c++17 -o bin/ej1 src/ej1/*.cpp

# Ejercicio 2
g++ -Wall -Wextra -Wpedantic -O2 -std=c++17 -o bin/ej2 src/ej2/*.cpp

# Ejercicio 3
g++ -Wall -Wextra -Wpedantic -O2 -std=c++17 -o bin/ej3 src/ej3/*.cpp

### Ejecutar los programas
./bin/ej1

./bin/ej2

./bin/ej3

### Requisitos
- Compilador g++ con soporte para C++17
- Flags requeridos: -Wall -Wextra -Wpedantic -O2 -std=c++17
