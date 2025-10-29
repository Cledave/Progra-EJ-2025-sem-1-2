#include<stdio.h>


int main(){
    int edad, euros;
    printf("Edad: ");
    scanf("%d", &edad);
    printf("Euros: ");
    scanf("%d", &euros);
    if (edad > 16){
        if (euros > 1000){
            printf("Es sujeto de impuestos\n");
        }
        else{
            printf("NO es sujeto de impuestos");
        }
    }
    else{
        printf("NO es sujeto de impuestos"); 
    }
    printf("Euros: %d\n", euros);
    return 0;
}