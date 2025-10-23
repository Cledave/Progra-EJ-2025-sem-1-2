#include <stdio.h>
#include <string.h> 

void creacion_tablero ();
void posibles_pasos(char *tablero[8][8], int x_2, int y_2);
void imprimir_tablero(char *tablero[8][8]);
void mostrar_posiciones(char *tablero[8][8],int x,int y);


int main(){
    creacion_tablero();;
    return 0;
}

//funciones

void creacion_tablero () {
    printf ("Tablero\n");
    char *tablero[8][8]= {{"8,A","8,B","8,C","8,D","8,E","8,F","8,G","8,H"},
                        {"7,A","7,B","7,C","7,D","7,E","7,F","7,G","7,H"},
                        {"6,A","6,B","6,C","6,D","6,E","6,F","6,G","6,H"},
                        {"5,A","5,B","5,C","5,D","5,E","5,F","5,G","5,H"},
                        {"4,A","4,B","4,C","4,D","4,E","4,F","4,G","4,H"},
                        {"3,A","3,B","3,C","3,D","3,E","3,F","3,G","3,H"},
                        {"2,A","2,B","2,C","2,D","2,E","2,F","2,G","2,H"},
                        {"1,A","1,B","1,C","1,D","1,E","1,F","1,G","1,H"},};

        int x_2, y_2;
        printf("Donde quieres posicionar el caballo?\nX:\t");
        scanf("%d",&x_2);
            while (x_2>8||x_2<0){
                printf("Invalido, repetir\tX:");
                scanf("%d",&x_2);
            }
        printf("Y:\t");
        scanf("%d",&y_2);
            while (y_2>8||y_2<0){
                printf("Invalido, repetir\tY:");
                scanf("%d",&y_2);
            }
        int x = x_2-1;
        int y = y_2-1;

    
    posibles_pasos(tablero,x,y);

    imprimir_tablero(tablero);

    mostrar_posiciones(tablero,x,y);
}

void posibles_pasos(char *tablero[8][8], int x, int y){
//posibles pasos
//|+2+1|+2-1|-2+1|-2-1
//|+1+2|+1-2|-1+2|-1-2
    tablero[x][y] = "&&&";

if (x+2<8&&y+1<8){
    tablero[x+2][y+1] = "&&&";
    }
if (x+2<8&&y-1>=0){
    tablero[x+2][y-1] = "&&&";
    }
if (x-2>=0&&y+1<8){
    tablero[x-2][y+1] = "&&&";
    }
if (x-2>=0&&y-1>=0){
    tablero[x-2][y-1] = "&&&";
    }   

if (x+1<8&&y+2<8){
    tablero[x+1][y+2] = "&&&";
    }
if (x+1<8&&y-2>=0){
    tablero[x+1][y-2] = "&&&";
    }
if (x-1>=0&&y+2<8){
    tablero[x-1][y+2] = "&&&";
    }
if (x-1>=0&&y-2>=0){
    tablero[x-1][y-2] = "&&&";
    }
}

void imprimir_tablero(char *tablero[8][8]){
    int i, j;
        for (i = 0; i < 8; i=i+1) {
            for (j = 0; j < 8; j=j+1) {
                printf("%s|", tablero[i][j]);
            }
            printf("\n");
        } 

}

void mostrar_posiciones(char *tablero[8][8],int x,int y){
    printf("Posiciones\n");
    int a=1;
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (strcmp(tablero[i][j], "&&&")==0) {
                printf("%d--%d,%d",a,i,j);
                a=a+1;
                if (x==i&&y==j){
                    printf(" (Original)");
                }
                printf("\n");

            }
        }
    }
}
