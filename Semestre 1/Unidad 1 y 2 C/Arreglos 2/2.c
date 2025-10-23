#include <stdio.h>
int main(){
    int num[8];
    int umbral;
    printf("Ingrese 8 numeros\n");
    for (int a=0;a<8;a=a+1) {
        scanf("%d",&num[a]);
    }    
    printf("\nIngresa umbral\n");
    scanf("%d",&umbral);

    for (int b=0;b<8;b=b+1){
        if(num[b]>umbral){
            printf("%d ",num[b]);
        }
    }
return(0);
}