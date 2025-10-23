/*Crea un programa que solicite al usuario una frase de hasta 100 caracteres (puede incluir espacios).

El programa debe recorrer la frase y reemplazar todos los espacios (' ') por guiones ('-') dentro del mismo arreglo, y luego mostrar la frase modificada.

Ejemplo de salida:

Ingrese una frase: lenguaje de programacion en C
Frase modificada: lenguaje-de-programacion-en-C

Criterios de evaluación:

    Lectura de la cadena de caracteres: 5 pts.
    Recorrido y modificación del arreglo: 15 pts.
    Muestra correcta de la salida: 10 pts.
*/

#include <stdio.h>
#include <string.h>
int main () {
 char arreglo[100];
    printf("Ingresa frase, max 100: \n");
    fgets(arreglo,100,stdin);
    

    for (int i=0;i<=strlen(arreglo);i=i+1){
        if (arreglo[i]==' '){
            arreglo[i]='-';
        }
    }
printf("%s",arreglo);
return(0);

}
