#include <stdio.h>

int main(){
    float nota;

    printf("Ingrese calificacion\n");
        scanf("%f",&nota);
    while (nota>=1.0&&nota<=7.0) {
            if (nota<4.0) {
                printf("Reprobado");
                return(0);
            } else if (nota>=4.0&&nota<5.5) {
                printf("Aprobado");
                return(0);
            } else printf("Distinguido");
                return(0);
    }
    printf("Fuera de rango");
    return(0);
    }
    
