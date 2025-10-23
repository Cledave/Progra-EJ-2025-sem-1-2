#include <stdio.h>
int main(){
    float matriz[5][3];

    //estudiante 1
    printf("Estudiante 1\n");
    for (int a=0;a<3;a=a+1){
            printf("Que nota te sacaste en la prueba %d?:",a+1);
            scanf("%f",&matriz[0][a]);
    }
        printf("\n");
    //estudiante 2
    printf("Estudiante 2\n");
    for (int a=0;a<3;a=a+1){
            printf("Que nota te sacaste en la prueba %d?:",a+1);
            scanf("%f",&matriz[1][a]);
    }
        printf("\n");
    //estudiante 3
    printf("Estudiante 3\n");
    for (int a=0;a<3;a=a+1){
            printf("Que nota te sacaste en la prueba %d?:",a+1);
            scanf("%f",&matriz[2][a]);
    }
    //estudiante 4
    printf("Estudiante 4\n");
    for (int a=0;a<3;a=a+1){
            printf("Que nota te sacaste en la prueba %d?:",a+1);
            scanf("%f",&matriz[3][a]);
    }  
    //estudiante 5
    printf("Estudiante 5\n");
    for (int a=0;a<3;a=a+1){
            printf("Que nota te sacaste en la prueba %d?:",a+1);
            scanf("%f",&matriz[4][a]);
    }
    float promedio_1;
    float promedio_2;
    float promedio_3;
    float promedio_4;
    float promedio_5;
    float suma_1=0.0;
    float suma_2=0.0;
    float suma_3=0.0;
    float suma_4=0.0;
    float suma_5=0.0;

    //estudiante 1/calcular promedio
    for (int a=0;a<3;a=a+1){
            suma_1 = suma_1 + matriz[0][a];
        }
        promedio_1 = suma_1/3;
        printf("Tu promedio , estudiante 1, es: %.1f    \n",promedio_1);

    //estudiante 2/calcular promedio
    for (int a=0;a<3;a=a+1){
            suma_2 = suma_2 + matriz[1][a];
        }
        promedio_2 = suma_2/3;
        printf("Tu promedio , estudiante 2, es: %.1f    \n",promedio_2);

    //estudiante 3/calcular promedio
    for (int a=0;a<3;a=a+1){
            suma_3 = suma_3 + matriz[2][a];
        }
        promedio_3 = suma_3/3;
        printf("Tu promedio , estudiante 3, es: %.1f    \n",promedio_3);

    //estudiante 4/calcular promedio
    for (int a=0;a<3;a=a+1){
            suma_4 = suma_4 + matriz[3][a];
        }
        promedio_4 = suma_4/3;
        printf("Tu promedio , estudiante 4, es: %.1f    \n",promedio_4);

    //estudiante 5/calcular promedio
    for (int a=0;a<3;a=a+1){
            suma_5 = suma_5 + matriz[4][a];
        }
        promedio_5 = suma_5/3;
        printf("Tu promedio , estudiante 5, es: %.1f    \n",promedio_5);

return(0);

}