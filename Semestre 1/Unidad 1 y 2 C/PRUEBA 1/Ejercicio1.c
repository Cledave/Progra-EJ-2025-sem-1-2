#include <stdio.h>
int main() {
    int n;                                                                              //asigno un N que va a servir para almacenar el numero principal
    int n_2 = 0;                                                                        //Este va a servir para almacenar el valor de la suma de los multiplos
    int i=3;                                                                            //Contador para saber cuando parar la suma
    printf("Ingrese un numero: ");                                                      
    scanf("%d",&n);                                                                     //Guarda el numero en la variable n (uso%d porque es un numero)
    for (i ;i<=n;i=i+3){                                                                // Cada vez que I es menor que N suma 3 a I
        n_2=n_2+ i;                                                                     //Y despues suma 3,6,9 (los valores que vaya tomando I) a N_2
    }
    printf("La suma de los multiplos de 3 menores o iguales a %d es: %d\n", n,n_2);     //printea N_2
    return 0;
}