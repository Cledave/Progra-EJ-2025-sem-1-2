#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char nombre[30];


    printf ("Ingresa tu nombre:  ");
    scanf("%s", nombre);

    printf ("Hola,%s\n",nombre);

    exit(0);

}