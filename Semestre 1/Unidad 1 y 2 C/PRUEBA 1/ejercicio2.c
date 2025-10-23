#include <stdio.h>
#include <string.h>

int main() {
    char frase[100];                                //Crea el char con un espacio para una frase de 100 caracteres
    int i=0;                                        //Crea I, que ahora es un representante de cada caracter y para saber cuando tiene que terminar de recorrer la frase
    printf("Ingrese una frase: ");                      
    fgets(frase, 100, stdin);                       //recoge la frase y la ingresa en frase, stdin es el metodo de registro del input

    for ( i < strlen(frase); i=i+1) {               //compara la lenght de la frase con I y suma 1 por cada caracter, no llega hasta el ultimo signo porque es un 0 
        if (frase[i] == ' ') {                      //cada vez que pasa por cada caracter y detecta un ' ' lo reemplaza por el '-'
            frase[i] = '-';                         //podia usar replace pero esto funciona casi igual de bien para casos simples, ademas no lo hemos visto
        }                                           // no uso == de nuevo, porque uno es de comparacion y el otro para reasignar valores, o algo asi
    }
    printf("Frase modificada: %s", frase);          //printra la frase modificada

    return 0;
}

