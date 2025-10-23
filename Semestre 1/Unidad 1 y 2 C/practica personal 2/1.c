/*
Ejercicio 4: Cálculo de promedio
Objetivo:
Practicar validación de entrada y uso de acumuladores.
Escribe un programa que permita al usuario ingresar una cantidad específica de calificaciones. Luego, calcula y muestra el promedio de esas calificaciones. 
Asegúrate de validar que cada calificación ingresada esté entre 1 y 7.
Se requiere:
- Validación con while
- Bucle for para recorrer las calificaciones
- Uso de una variable acumuladora
*/

#include <stdio.h>
int main(){
    float nota;
    int contador;
    float suma=0;
    float promedio;

    printf("Cuantas notas son?\n");
    scanf("%d",&contador);
    printf("Ingresa tus notas\n");
    for (int i=0;i<contador;i=i+1){
        scanf("%f",&nota);
        if (nota>7.0||nota<1.0){
            printf("Nota no valida");
            return(0);
        } 
        suma=suma+nota;
    }
    promedio=suma/contador;
    printf("Tu promedio de notas es=%.2f",promedio);
    return(0);
    


    



}