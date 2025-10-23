#include <stdio.h>

int main() {
    int ext = 1000 ;
    int ent = 0;

    while ( ext >= 200) {
        printf("Introduzca numero de unidades entregadas:   ");
        scanf ("%d", &ent);

        ext = ext - ent;
    }
printf("El inventario de unidades ha bajado de 200, debe comunicarlo\nUnidades: %d",ext );

}