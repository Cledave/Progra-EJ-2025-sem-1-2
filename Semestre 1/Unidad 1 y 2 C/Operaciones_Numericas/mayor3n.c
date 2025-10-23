#include <stdio.h>
int main(   ) {
    int num1, num2, num3;

    printf ("Introduce primer numero:   ");
    scanf ("%d", &num1);

    printf ("Introduce segundo numero:   ");
    scanf ("%d", &num2);

    printf ("Introduce tercer numero:   ");
    scanf ("%d", &num3);

    if (num1 >= num2 && num1 >= num3) {
        printf ("El mayor es: %d\n",num1);
    } else if (num2 >= num1 && num2 >= num3) { 
        printf ("El mayor es: %d\n",num2);
    } else if (num3 >= num1 && num3 >= num2) {
        printf ("El mayor es: %d\n",num3);
    }
}    

