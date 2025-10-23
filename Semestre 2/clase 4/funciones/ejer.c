#include <stdio.h>
//ARREGLAR PARA NUMEROS IGUALES
int main(){
    float a=0.0;
    float b=0.0;
    float c=0.0;
    float mayor=0;
    printf("Ingrese numero 1:\t");
    scanf ("%f",&a);
    if (a)
    printf("Ingrese numero 2:\t");
    scanf ("%f",&b);
    printf("Ingrese numero 3:\t");
    scanf ("%f",&c);

    if (a>b&&a>c){
        printf("\n%.1f es el mayor",a);
        mayor
    }
    if (b>a&&b>c){
        printf("\n%.1f es el mayor",b);
    }
    if (c>a&&c>b){
        printf("\n%.1f es el mayor",c);
    }

}