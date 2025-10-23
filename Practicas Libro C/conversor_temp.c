#include <stdio.h>

int main(){
    char decision;
    printf("Ingrese F o C\n");
    scanf("%s", &decision);
    if (decision == 'F' || decision == 'f' ){
        float celsius;
        float far;
        printf("Ingrese fahrenheit\n");
        scanf("%f",&far);
        celsius = (far - 32.0) * (5.0/9.0);
        printf("Su conversion de far (%.0f) a cel es (%.2f)",far,celsius);
    } else if (decision == 'c' || decision == 'C' ){
        float celsius;
        float far;
        float div = 9.0/5.0;
        printf("Ingrese C\n");
        scanf("%f",&celsius);
        far = (celsius*div) + 32;
        printf("Su conversion de cel (%.0f) a far es (%.2f)", celsius, far);
    }

}