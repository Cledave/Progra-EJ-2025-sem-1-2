/*
Ejercicio

Escribe un programa que solicite al usuario ingresar una temperatura en grados Celsius. Luego, utilizando una estructura if – else if – else, el programa debe clasificar la temperatura según los siguientes criterios:

Menor a 0°C: Temperatura bajo cero
Entre 0°C y 18°C: Temperatura fría
Mayor a 18°C y hasta 30°C: Temperatura templada
Mayor a 30°C: Temperatura calurosa
*/
#include <stdio.h>

int main() {
float temperatura;
    printf("Ingrese temperatura\n");
    scanf("%f",&temperatura);
    if (temperatura<0) {
        printf("T bajo cero");
    }
    else if (temperatura>0 && temperatura<18) {
        printf("T fria");
    }
    else if (temperatura>18 && temperatura<30){
        printf("T templada");
    }
    else {
        printf("Temperatura calurosa");
    }
return(0);
}