#include <stdio.h>
int esperfecto (int n);
int primo_val (int n);

int main(){
    int n;
    int aux;

    printf("Ingrese un numero\n");
    scanf("%d",&n);

    aux = esperfecto(n);
    if (aux == 1){
        printf("El numero %d es perfecto",n);
    }
    else {
        printf("%d No es perfecto",n);
    }
    return(0);
}

/*
Definicion de las funciones
*/

int esperfecto (int n){
    int acumulador=0;
    int i = 1;

    while (i<n){
        if (n%i==0){
            acumulador=acumulador+i;
        }
        i=i+1;
    }
    if (acumulador==n){
        return(1);
    } else {
        return(0);
    }
}


/*int primo_val (int n){
    for (int i=2;i<n;i=i+1){
        if (n%i == 0){
            return 0;
        }
    }        
    return 1;                                                                                                                   
}
*/
