#include <stdio.h>

#define N 5

typedef struct coord{
    int fil;
    int col;
    int valor;
} COORD;

void lectura(char *, int [][N]);
void muestra_matriz(int [][N]);
COORD busca_silla(int [][N]);
void salida (COORD, int [][N]);

int main(){
    int m[N][N];
    COORD silla;
    lectura ("1.txt", m);
    silla = busca_silla(m);
    salida(silla, m);
    return 0;
}

void lectura(char *nombre, int m[][N]){
    FILE *ent;
    ent = fopen(nombre, "r");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            fscanf(ent, "%d", &m[i][j]);
        }
    }
    fclose(ent);
}

void muestra_matriz(int m[][N]){
    for (int i= 0; i < N; i++){
        for(int j=0; j < N; j++){
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }
}

COORD busca_silla(int m[][N]) {
    COORD silla;
    int lo_encontre = 0;
    int menor_fila;
    for (int i = 0; i < N; i++) {
        int menor_fila = m[i][0];
        int menor_col = 0;
        for (int j = 1; j < N; j++) {
            if (m[i][j] < menor_fila) {
                menor_fila = m[i][j];
                menor_col = j;
    
            }
        }

        int es_silla = 1;
        for (int k = 0; k < N; k++) {
            if (m[k][menor_col] > menor_fila) {
                es_silla = 0;
                break;
            }
        }

        if (es_silla) {
            silla.fil = i;
            silla.col = menor_col;
            silla.valor = menor_fila;
            lo_encontre = 1;
        }
    }

    if (!lo_encontre) {
        silla.fil = -1;
        silla.col = -1;
        silla.valor = -1;
    }
    return silla;
}

void salida (COORD silla, int m[][N]){
    if (silla.fil != -1){
        printf("\nPosicion de la silla [%d][%d] = %d\n", silla.fil, silla.col, silla.valor);
    }
    else{
       printf("\nLa matriz no tiene punto silla.\n");
    }
    printf("\nMatriz\n");
    muestra_matriz(m);
}