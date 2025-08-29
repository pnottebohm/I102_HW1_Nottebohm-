# I102_HW1_Nottebohm-
## Compilación y Ejecución

### Crear directorio bin
mkdir -p bin

### Compilar ejercicios individuales
# Ejercicio 1
g++ -Wall -Wextra -Wpedantic -O2 -std=c++17 -o bin/ej1 src/ej1/*.cpp

# Ejercicio 2
g++ -Wall -Wextra -Wpedantic -O2 -std=c++17 -o bin/ej2 src/ej2/*.cpp

# Ejercicio 3
g++ -Wall -Wextra -Wpedantic -O2 -std=c++17 -o bin/ej3 src/ej3/*.cpp

### Compilar todos los ejercicios
mkdir -p bin
g++ -Wall -Wextra -Wpedantic -O2 -std=c++17 -o bin/ej1 src/ej1/*.cpp
g++ -Wall -Wextra -Wpedantic -O2 -std=c++17 -o bin/ej2 src/ej2/*.cpp
g++ -Wall -Wextra -Wpedantic -O2 -std=c++17 -o bin/ej3 src/ej3/*.cpp
echo "Compilación completada."

### Ejecutar los programas
./bin/ej1
./bin/ej2
./bin/ej3

### Requisitos
- Compilador g++ con soporte para C++17
- Flags requeridos: -Wall -Wextra -Wpedantic -O2 -std=c++17
