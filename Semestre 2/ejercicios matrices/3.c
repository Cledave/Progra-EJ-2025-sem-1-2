#include <stdio.h>

int suma_div(int numero);
int resultado(int min,int max);

int main() {
    int min=0;
    int max=10000;
    int numero;
    resultado(min,max);
} 

//funciones

int suma_div(int numero){
    int suma=0;
    for (int i=1; i<numero; i=i+1) {
        if (numero%i== 0) {
            suma = suma + i;
        }
    }
    //printf("%d",suma);
    return suma;
}

int resultado(int min,int max){
    for (int m = min; m < max; m=m+1) {
            for (int n = min; n < max; n=n+1) {
                if (suma_div(n) == m && suma_div(m) == n) {
                    printf("par magico: %d--%d\n", m, n);
                    
            }
        }
    }

}