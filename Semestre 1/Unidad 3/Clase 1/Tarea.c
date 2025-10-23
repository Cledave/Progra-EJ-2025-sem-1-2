#include <stdio.h>

    float sumar(float a, float b){
        return a + b;
    }
    float restar(float a, float b){
        return a - b;
    }
    float multiplicar(float a, float b){
        return a * b;
    }
    float dividir(float a, float b){ //(debe verificar que b != 0)
        return a/b;
    } 

int main(){
    int dec;
    float a;
    float b;
    float resultado;
    printf("Ingresa los numeros;\n");
    printf("Primer Numero:\t");
    scanf("%f",&a);
    printf("Segundo Numero:\t");
    scanf("%f",&b);
    printf("\nQue operacion quieres realizar?:\n");
    printf("1. Sumar\n2. Restar\n3. Multiplicar\n4. Dividir\n\n");
    
    scanf("%d",&dec);
    if (dec == '1'){
        resultado = sumar(a,b);
        printf("\nResultado = %.2f",resultado);
    } else if (dec == 2){
        resultado = restar(a,b);
        printf("\nResultado = %.2f",resultado);
    } else if (dec == 3){
        resultado = multiplicar(a,b);
        printf("\nResultado = %.2f",resultado);
    } else if (dec == 4){
        if (b==0){
            printf("\nOperacion no se puede completar");
            return(0);
        } else {
            resultado = dividir(a,b);
            printf("\nResultado = %.2f",resultado);
        }
    }
}