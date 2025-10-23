#include <stdio.h>  //PRINCIPAL
#include <string.h> //CADENAS
#include <ctype.h>  //TOLOWER,TOUPPER
#include <stdlib.h> //CHAR

int main(){
    char nombre[10];

    printf("Ingresa tu nombre\n");
    fgets(nombre, 10, stdin);

    printf("\n%s",nombre);

    exit(0);

}