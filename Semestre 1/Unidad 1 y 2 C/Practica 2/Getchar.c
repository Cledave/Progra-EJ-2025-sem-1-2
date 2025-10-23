#include <stdio.h> 
#include <stdlib.h> 
int main() { 
    char c;             //Coloco una string llamada C
  
    c = getchar();       // Esto actua con scanf("%s",&c)
    while (c!= EOF) {   //'\n' detecta el salto de linea (En este caso EOF)
        putchar(c);      // imprime el caracter C en la consola
        c = getchar();   //solicita de nuevo C para repetir
    } 
    exit(0);
}