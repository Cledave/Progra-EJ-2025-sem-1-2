#include <stdio.h>

void cuadrado (int *a){
    *a = *a * *a;
}
int main(){
    int a = 5;
    printf("Orig=%d\n",a);
    cuadrado(&a);
    printf("cuadrado=%d\n",a);
    return(0);
}
