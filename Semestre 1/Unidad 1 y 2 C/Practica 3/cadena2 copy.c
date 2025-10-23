#include <stdio.h>
#include <string.h>


int main() {
    int i=0;
    char C[] = "Hola Mundo"; //cadena inicializacion

    while (i<strlen(C)) {
        printf("%c\n",C[i]);
        i = i+1;
        
    }
    return(0);

}