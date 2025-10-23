#include <stdio.h>
int main(){
    int num;
    int suma=0;
    printf("Ingresa numero\n");
    scanf("%d",&num);
    for (int i=1;i<=num;i=i+1){
        if (i%3==0){
            suma=suma+i;
        }
        //printf("%d",i);
    }
    printf("%d",suma);
return(0);
}