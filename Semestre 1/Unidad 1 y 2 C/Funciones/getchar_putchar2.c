#include <stdio.h>
#include <stdlib.h>

int main() {
    char c;         //variable para almaecer un solo caracter leido
    c = getchar();  //Lee el primer caracter e la entrada estandar (teclado)

    /*Bucle que lee caracteres hasta encontrar el final del archuvo (EOF)
    en sistemas UNIX/LINUX, EOF Se envia con la CTRL+D
    En windows, con CTRL+Z seguido de enter
    */
    while ((c = getchar())!=EOF ) {
        putchar (c);    //Escribe el caracter en la salida estandar (pantalla)
        c = getchar();  //Lee el siguiente caracter

    }
    //Finaliza el programa exitosamente 
    exit(0);





}