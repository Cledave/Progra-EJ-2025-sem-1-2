//Coloco un numero n y me suma desde el 0 hasta n todos los que encuentran por medio, 1+2+3+4+5.....etc

#include <stdio.h>
int main(){
    int num_max;
    int suma;
    int pasos;
    
    printf("Numero max\n");
    scanf("%d",&num_max);
    suma=0;
    while (pasos<num_max) {
        suma = suma + pasos;
        pasos = pasos+1;

    }
    printf ("la suma es %d", suma+num_max);
return(0);
}