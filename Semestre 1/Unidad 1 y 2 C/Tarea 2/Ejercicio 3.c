#include <stdio.h> 

int main(){
    int suma=0;
    int num=1;
    int cantidad_numeros=0;
    int numeros_may_100=0;

    printf("Ingresa un numero\n");
    while (num!=0) {
        scanf("%d",&num);
        cantidad_numeros+=1;
        if (num>=100){
            numeros_may_100+=1;
        }
        suma+=num;
        }
    printf("Cantida de numeros = %d\n", (cantidad_numeros-1));
    printf("Suma               = %d\n", suma);
    printf("Mayores a 100      = %d\n", numeros_may_100);

    return 0;

    
    }
