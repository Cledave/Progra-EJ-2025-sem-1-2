#include <stdio.h>
/*
Para tributar un determinado impuesto en europa sse debe ser mayor de 16 años y tener unos ingresos igulaes o superiores a 1000 euros
mensuales.Programa debe:
1- Preguntar al usuario su edad
2- Preguntar ingresos
3- Si cumple condiciones enviar mensaje que debe tributar.
*/
int main(){
    int edad;
    int ingresos;
    printf("Ingrese edad:\n");
    scanf("%d",&edad);
    printf("Ingrese ingresos mensuales:\n");
    scanf("%d",&ingresos);
    if (edad>16&&ingresos>=1000){
        printf("Debe tributar.");
        return(0);
    }
    printf("No debe tributar.");
}