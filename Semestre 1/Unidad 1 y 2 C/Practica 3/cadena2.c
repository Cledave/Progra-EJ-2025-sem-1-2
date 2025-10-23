#include <stdio.h>
#include <string.h>

int main() {
    int i;
    char saludo[] = "Hola Mundo"; //cadena inicializacion

    for (i=0; i < strlen(saludo); ++i) // empieza desde el termino [0] de la cadena y los imprimer 1x1
        printf("%c\n", saludo[i]); // imprimer el termino i, que empiza por 0 y termina en el largo (strlen) de la cadena

    return(0);
}