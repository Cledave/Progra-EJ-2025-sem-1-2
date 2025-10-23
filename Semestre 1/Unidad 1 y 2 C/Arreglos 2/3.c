#include <stdio.h>
int main(){
    int num[10];
    int contador=0;
    printf("Ingrese 10 numeros\n");
    for (int a=0;a<10;a=a+1) {
        scanf("%d",&num[a]);
    }
    for (int b=0;b<10;b=b+1){
        if(num[b]>=50&&num[b<=100]){
            contador=contador+1;
        }
    }
    printf("%d",contador);
    return(0);          
}