#include <stdio.h>
int main(){
    int filas=3;
    int columnas=5;   

    int matriz[filas][columnas];
    
    for (int a=0;a<filas;a=a+1){
        for (int b=0;b<columnas;b=b+1){
            printf("[linea %d][ dia %d]:\t",a+1,b+1);
            scanf("%d",&matriz[a][b]);
        }
    }
    
    int pro_linea_1=0;
    int pro_linea_2=0;
    int pro_linea_3=0;

    //linea1
    for (int a=0;a<columnas;a=a+1){
        pro_linea_1=pro_linea_1+matriz[0][a];
    } 
    printf("\n");
    //linea2
    for (int a=0;a<columnas;a=a+1){
        pro_linea_2=pro_linea_2+matriz[1][a];
    } 
    printf("\n");
    //linea3
    for (int a=0;a<columnas;a=a+1){
        pro_linea_3=pro_linea_3+matriz[2][a];
    } 
    printf("\n");

    int mayor=0;
    for (int a=0;a<filas;a=a+1){
        for (int b=0;b<columnas;b=b+1){
            if (mayor<matriz[a][b]){
                mayor=matriz[a][b];
            }
        }
    }

    int linea;
    int dia;

    for (int a=0;a<filas;a=a+1){
        for (int b=0;b<columnas;b=b+1){
            if (matriz[a][b]==mayor){
                linea=a;
                dia=b;
            }
        }
    }

    printf("Produccion total de la linea 1:%d\n",pro_linea_1);
    printf("Produccion total de la linea 2:%d\n",pro_linea_2);
    printf("Produccion total de la linea 3:%d\n",pro_linea_3);
    printf("Mayor valor individual:%d [Linea %d][Dia %d]",mayor,linea+1,dia+1);


}