#include <stdio.h>

int main(){
    int num[5];
    printf("Ingrese 5 numeros\n");
    for (int i=0;i<5;i=i+1) {
        scanf("%d",&num[i]);
    }    
    printf("\n");
    for (int b=0;b<5;b=b+1){
        printf("%d ",num[b]);
    }


}