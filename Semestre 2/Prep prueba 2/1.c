#include <stdio.h>

int TABLERO();

int main()
{
    TABLERO();
}

//FUNCIONES

int TABLERO(){
    FILE *num; //crea un puntero al archivo
    num=fopen("1.txt","r"); //abre el archivo y lo asigna como referencia a num, la r es para indicar que solo estamos leyendo el archivo
    int matriz[5][5]; //crea la matriz "matrix" con punteros 
    //el bucle que sirve para guardar los datos del archivo en la matriz
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            fscanf(num,"%i",&matriz[i][j]); //es la funcion que lee y escribe, le pasamos el tipo de archivo
        }
    }
    /*
    imprimir la matriz, para comprobaciones
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    */
   
//menor de la fila
int menor_fila;
int columna_menor;
for (int i=0; i<5;i++){
    menor_fila=matriz[i][0];
        for (int j=0;j<5;j++){
            if (matriz[i][j]<menor_fila){
                menor_fila=matriz[i][j];
                columna_menor = j;
            }
        }
    for (int k=0;k<5;k++){
        if (matriz[k][columna_menor]){

        }
    }
    printf("%d-%d\n",menor_fila,columna_menor);
    }
}



//encontrar el menor de cada fila, y despues el mayor de esos.


