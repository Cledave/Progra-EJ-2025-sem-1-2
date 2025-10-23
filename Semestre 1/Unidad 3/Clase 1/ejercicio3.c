#include <stdio.h>

//PROMEDIO ENTRE 2 NUMEROS
float promedio (float a, float b){
    return ((a+b)/2);
} 

int main(){
    float g;    
    float h;
    printf("Ingresa tus numeros:\n");
    printf("Numero 1:\n");
        scanf("%f",&g);
    printf("Numero 2:\n");
        scanf("%f",&h);
    float resultado = promedio (g,h);
    printf("Tu promedio es: %.2f\n",resultado);
    return(0);
}
