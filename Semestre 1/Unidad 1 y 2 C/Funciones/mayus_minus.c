#include <ctype.h>
#include <stdio.h>

int main(){
    char c;
    while ((c=getchar())!=EOF) {
        
        //Convierte el caracter en mayuscula si es letra
        c = toupper (c);
        
        //Escribe el caracter resultante en la salida estandar
        putchar(c);

    }

    return(0);


}