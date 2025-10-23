//Autor: Claudio Sepúlveda
#include <stdio.h>

int main(){
    int inicio;
    int fin;
    int cont=0;
    int mayor=0;

    printf("Escribe INICIAL:\t");
    scanf("%d",&inicio);
    printf("Escribe FINAL:\t");
    scanf("%d",&fin);

    for (int i=inicio;i<=fin;i=i+1){
        int num = i;
        int contador=0;
        printf("%d ",num);
        while (num!=1){
            if (num%2==0){
                num = num/2;
            } else {
                num = (num*3)+1;
            }
            printf("%d ",num);
            contador=contador+1;
        } if (contador > cont) {
          cont = contador;
          mayor = i;
          }
    }
    printf("El contador mas grande es de %d con %d numeros",mayor,cont);
return 0;
}
