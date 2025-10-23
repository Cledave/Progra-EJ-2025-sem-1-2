#include <stdio.h>
int main(){
float num[5];
float suma=0;
float contador=0;
printf("Ingresa 5 valores\n");
for (int i=0; i<5;i=i+1) {
    scanf("%f",&num[i]);
    contador=contador+1;
    suma=suma+num[i];  
}
printf("Tu arreglo es = ");
for (int i=0; i<5;i=i+1) {
    printf("%.1f ", num[i]);
}

float promedio = suma/contador;
printf("\nLa suma de los valores de tu arreglo es = ");
printf("%.1f",suma);
printf("\nEl promedio de tus valores es = ");
printf("%.1f",promedio);
return(0);
}