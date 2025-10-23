#include <stdio.h>
int main(){
    float nota[6];
    float aprob=4.0;
    float cant_aprob=0.0;
    float porc_aprob=0.0;

    for (int cont=0;cont<7;cont=cont+1){
        printf("Ingresa nota estudiante N%d     ",cont+1);
        scanf("%f",&nota[cont]);
    }
    for (int cont=0;cont<7;cont=cont+1){
        if (nota[cont]>=4.0){
            cant_aprob=cant_aprob+1;
        }
    }
    for (int cont=0;cont<7;cont=cont+1){
        printf("%.1f\n",nota[cont]);
    }

    porc_aprob=(cant_aprob*100)/7;
    float baja=nota[0];
    for (int cont=0;cont<7;cont=cont+1){
        if (baja>nota[cont]){
            baja = nota[cont];
        }
    }
    printf("Cantidad de estudiantes aprobados:   %.0f\n",cant_aprob);
    printf("Porcentaje de estudiantes aprobados: %.2f\n",porc_aprob);
    printf("Nota mas baja registrada:            %.1f",baja);
    return(0);
}