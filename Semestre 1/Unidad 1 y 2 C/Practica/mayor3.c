//compara 3 numeros y ve cual es mayor

#include <stdio.h>
int main(){
    int num1;
    int num2;
    int num3;

    printf("Ingresa numeros\n");
    scanf("%d",&num1);
    scanf("%d",&num2);
    scanf("%d",&num3);

    if (num1>num2 && num1>num3){
        printf ("Numero %d es el mayor ",num1);
        return (0);
    }
    if (num2>num1 && num2>num3){
        printf ("Numero %d es el mayor ",num2);
        return (0);
    }
    if (num3>num1 && num3>num2){
        printf ("Numero %d es el mayor ",num3);
        return (0);
    }

return (0);

}