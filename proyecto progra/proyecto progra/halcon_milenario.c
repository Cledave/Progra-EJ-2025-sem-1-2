#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

// Estructura para representar una posición
typedef struct {
    int fila;
    int columna;
} Posicion;

// Estructura para la nave
typedef struct {
    Posicion pos;
    char orientacion; // 'N', 'E', 'S', 'O'
} Nave;

// Función para girar a la derecha
char girarDerecha(char orientacion) {
    switch(orientacion) {
        case 'N': return 'E';
        case 'E': return 'S';
        case 'S': return 'O';
        case 'O': return 'N';
        default: return orientacion;
    }
}

// Función para girar a la izquierda
char girarIzquierda(char orientacion) {
    switch(orientacion) {
        case 'N': return 'O';
        case 'O': return 'S';
        case 'S': return 'E';
        case 'E': return 'N';
        default: return orientacion;
    }
}

// Función para avanzar según la orientación
Posicion avanzar(Posicion pos, char orientacion) {
    Posicion nueva = pos;
    switch(orientacion) {
        case 'N': nueva.fila--; break;
        case 'S': nueva.fila++; break;
        case 'E': nueva.columna++; break;
        case 'O': nueva.columna--; break;
    }
    return nueva;
}

// Función para verificar si una posición está fuera del mapa
int fueraDelMapa(Posicion pos, int filas, int columnas) {
    return (pos.fila < 0 || pos.fila >= filas || 
            pos.columna < 0 || pos.columna >= columnas);
}

// Función para verificar si hay peligro en una posición
int hayPeligro(Posicion pos, Posicion estrellas[], int numEstrellas, 
               Posicion destructores[], int numDestructores) {
    int i;
    
    // Verificar estrellas
    for(i = 0; i < numEstrellas; i++) {
        if(estrellas[i].fila == pos.fila && estrellas[i].columna == pos.columna) {
            return 1;
        }
    }
    
    // Verificar destructores
    for(i = 0; i < numDestructores; i++) {
        if(destructores[i].fila == pos.fila && destructores[i].columna == pos.columna) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    FILE *entrada, *salida;
    int filas, columnas;
    Nave halcon;
    Posicion destino;
    Posicion estrellas[MAX_SIZE * MAX_SIZE];
    Posicion destructores[MAX_SIZE * MAX_SIZE];
    int numEstrellas, numDestructores;
    int numOrdenes;
    char ordenes[10000];
    int i;
    char resultado[50];
    
    // Abrir archivo de entrada
    entrada = fopen("situacioninicial.txt", "r");
    if(entrada == NULL) {
        printf("Error: No se pudo abrir el archivo situacioninicial.txt\n");
        return 1;
    }
    
    // Leer tamaño del mapa
    fscanf(entrada, "%d", &filas);
    fscanf(entrada, "%d", &columnas);
    
    // Leer posición inicial de la nave
    fscanf(entrada, "%d %d", &halcon.pos.fila, &halcon.pos.columna);
    
    // Leer posición del destino
    fscanf(entrada, "%d %d", &destino.fila, &destino.columna);
    
    // Leer estrellas
    fscanf(entrada, "%d", &numEstrellas);
    for(i = 0; i < numEstrellas; i++) {
        fscanf(entrada, "%d %d", &estrellas[i].fila, &estrellas[i].columna);
    }
    
    // Leer destructores
    fscanf(entrada, "%d", &numDestructores);
    for(i = 0; i < numDestructores; i++) {
        fscanf(entrada, "%d %d", &destructores[i].fila, &destructores[i].columna);
    }
    
    // Leer orientación inicial
    fscanf(entrada, " %c", &halcon.orientacion);
    
    // Leer número de órdenes
    fscanf(entrada, "%d", &numOrdenes);
    
    // Leer secuencia de órdenes
    fscanf(entrada, "%s", ordenes);
    
    fclose(entrada);
    
    // Verificar si la posición inicial ya tiene peligro
    if(hayPeligro(halcon.pos, estrellas, numEstrellas, destructores, numDestructores)) {
        strcpy(resultado, "Nave destruida");
    } else {
        // Simular las órdenes
        strcpy(resultado, "Llegamos a salvo");
        
        for(i = 0; i < numOrdenes && resultado[0] == 'L'; i++) {
            char orden = ordenes[i];
            
            if(orden == 'A') {
                // Avanzar
                Posicion nuevaPos = avanzar(halcon.pos, halcon.orientacion);
                
                // Verificar si sale del mapa
                if(fueraDelMapa(nuevaPos, filas, columnas)) {
                    strcpy(resultado, "Nave perdida");
                    break;
                }
                
                // Verificar si hay peligro
                if(hayPeligro(nuevaPos, estrellas, numEstrellas, destructores, numDestructores)) {
                    strcpy(resultado, "Nave destruida");
                    break;
                }
                
                // Mover la nave
                halcon.pos = nuevaPos;
                
            } else if(orden == 'D') {
                // Girar a la derecha
                halcon.orientacion = girarDerecha(halcon.orientacion);
                
            } else if(orden == 'I') {
                // Girar a la izquierda
                halcon.orientacion = girarIzquierda(halcon.orientacion);
            }
        }
        
        // Verificar si llegó al destino
        if(resultado[0] == 'L') {
            if(halcon.pos.fila != destino.fila || halcon.pos.columna != destino.columna) {
                strcpy(resultado, "Nave perdida");
            }
        }
    }
    
    // Escribir resultado en archivo de salida
    salida = fopen("situacionfinal.txt", "w");
    if(salida == NULL) {
        printf("Error: No se pudo crear el archivo situacionfinal.txt\n");
        return 1;
    }
    
    fprintf(salida, "%s\n", resultado);
    fclose(salida);
    
    printf("Simulacion completada. Resultado: %s\n", resultado);
    
    return 0;
}
