#include <stdio.h>
#include <stdlib.h>
//guardar C en una cadena y despues imprima toda la cadena
int main() {
    char c2 [10];
    char c;
    while ((c = getchar()) != EOF) {
        c2[10]=(char)c;
        printf("%s",c2);
    }
    
    exit(0);
}