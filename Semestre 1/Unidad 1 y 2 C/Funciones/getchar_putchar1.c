#include <stdio.h>
#include <stdlib.h>

int main() {
    char c;         //variable para almaecer un solo caracter leido
    c = getchar();  //Lee el primer caracter e la entrada estandar (teclado)
    //Mientras el caracter leido NO sea salto de linea (\n)
    while (c != '\n') {
        putchar (c);    //Escribe el caracter en la salida estandar (pantalla)
        c = getchar();  //Lee el siguiente caracter

    }
    //Cuando se detecta "\n", se imprime un salto de linea adicional
    printf ('\n');
    //Finaliza el programa exitosamente 
    exit(0);





}