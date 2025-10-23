#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

float leer_valor(char nombre) {
    char input[100];
    float valor = 0;
    int valido = 0;

    while (!valido) {
        printf("Ingresa %c: ", nombre);
        scanf("%s", input);

        // Si comienza con sqrt( y termina con )
        if (strncmp(input, "sqrt(", 5) == 0 && input[strlen(input) - 1] == ')') {
            char numero_str[90];
            strncpy(numero_str, input + 5, strlen(input) - 6); // copia lo que está entre paréntesis
            numero_str[strlen(input) - 6] = '\0'; // asegura el final de cadena

            float num;
            if (sscanf(numero_str, "%f", &num) == 1 && num >= 0) {
                valor = sqrt(num);
                valido = 1;
            } else {
                printf("Raíz inválida o negativa. Intenta de nuevo.\n");
            }
        }
        // Si es un número normal
        else if (sscanf(input, "%f", &valor) == 1) {
            valido = 1;
        } else {
            printf("Entrada inválida. Intenta de nuevo.\n");
        }

        // En el caso de A, no puede ser cero
        if (nombre == 'A' && valor == 0) {
            printf("A no puede ser 0. Reingresa.\n");
            valido = 0;
        }
    }

    return valor;
}

int main() {
    float a = leer_valor('A');
    float b = leer_valor('B');
    float c = leer_valor('C');

    printf("Valores ingresados:\nA = %.2f\nB = %.2f\nC = %.2f\n", a, b, c);
    return 0;
}
