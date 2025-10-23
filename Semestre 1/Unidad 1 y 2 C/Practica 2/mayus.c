#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    c = getchar();
    while (c != EOF) {
        //printf("\n") Este salto de linea haria que las letras se mostraran 1 a la vez
        c = tolower(c);  //Aplica las mayusculas a todo el texto, una letra a la vez, puedo cambiarlo por tolower(c)
        putchar(c);
        c = getchar();
    }

    return(0);
}