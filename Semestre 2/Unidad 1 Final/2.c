#include <stdio.h>
#include <math.h>

void operacion (int n1, int n2, char oper, float* resul,int *error);
char menu (void);

int main(){
    int n1,n2;
    int error;
    char oper;
    float resul;

    oper = menu();

    operacion (n1,n2,oper,&resul,&error);
    printf("resultado: %.2f\t",resul);
}

/* 
Definicion de las funciones
*/

void operacion (int n1, int n2, char oper, float* resul,int *error){
    printf("Numero 1:\t");
    scanf("%d",&n1);
    printf("\nNumero 2:\t");
    scanf("%d",&n2);
    if (oper == '+'){
        *resul = n1 + n2;
    }
    if (oper == '-'){
        *resul = n1 - n2;
    }
    if (oper == '*'){
        *resul = n1 * n2;
    }
    if (oper == '/'){
        *resul = n1 / n2;
    }
    if (oper == '^'){
        *resul = pow(n1,n2);
    }
    if (oper == '!'){
        printf("ERROR");
    }
    if (oper == 's'|| oper == 'S'){
        printf("Cerrando");
    }
}

char menu (void){
    char oper;
    printf("\t\tMenu\n");
    printf("+ --> Sumar\n");
    printf("- --> Restar\n");
    printf("* --> Multiplicar");
    printf("/ --> Dividir\n");
    printf("p --> Potencial\n");
    printf("! --> Factorial\n");
    printf("S --> Salir\n");
    printf("\n\n\tOperacion:\t");
    scanf("%c", &oper);
    return oper;
}