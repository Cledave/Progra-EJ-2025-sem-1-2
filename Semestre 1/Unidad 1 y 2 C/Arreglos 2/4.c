#include <stdio.h>

int main(){
    int num[7];
    int mayor=0;
    printf("Ingrese 7 numeros\n");
    for (int a=0;a<7;a=a+1) {
        scanf("%d",&num[a]);
    } 
    for (int b=0;b<7;b=b+1) {
        if (num[b]>mayor){
            mayor=num[b];
        }
    } 
    printf("\nMayor=%d",mayor);
return(0);
}
