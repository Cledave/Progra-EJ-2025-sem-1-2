#include <stdio.h>
#define FILAS 10
#define COLUMNAS 10
#define INICIOx 0
#define INICIOy 0

/* Matriz */
char laberinto[FILAS][COLUMNAS] = {
    {'A', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' '},
    {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' '},
    {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' '},
    {' ', '#', '#', ' ', '#', '#', '#', ' ', '#', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
    {'#', '#', '#', '#', '#', ' ', '#', ' ', '#', ' '},
    {' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' '},
    {' ', '#', '#', '#', '#', ' ', '#', '#', '#', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', 'B'}};
// Prototipos de funciones
void mostrarlaberinto();
int calcularRutas(char laberinto[FILAS][COLUMNAS],int x,int y);

int main(){
    printf("----- BUSCANDO EL CAMINO DEL laberinto RECURSIVO ---\n");
    printf("Buscando el camino desde A hasta B \n");
    mostrarlaberinto();
    if(calcularRutas(laberinto, INICIOx,INICIOy)){
        printf("Hecho\n");
        mostrarlaberinto();
    } else {
        printf("Sin camino\n");
    }
    return 0;

}

//funciones

void mostrarlaberinto(){
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            printf("%c ", laberinto[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int calcularRutas(char laberinto[FILAS][COLUMNAS], int x,int y){
    if (laberinto[x][y]=='B'){
        return 1;
    }
    laberinto[x][y] = 'c';
    //movimientos
    // Mover hacia abajo
    if (x + 1 < FILAS && (laberinto[x + 1][y] == ' ' || laberinto[x + 1][y] == 'B')) {
        if (calcularRutas(laberinto, x + 1, y)) return 1;
    }

    // Mover hacia arriba
    if (x - 1 >= 0 && (laberinto[x - 1][y] == ' ' || laberinto[x - 1][y] == 'B')) {
        if (calcularRutas(laberinto, x - 1, y)) return 1;
    }

    // Mover hacia la derecha
    if (y + 1 < COLUMNAS && (laberinto[x][y + 1] == ' ' || laberinto[x][y + 1] == 'B')) {
        if (calcularRutas(laberinto, x, y + 1)) return 1;
    }

    // Mover hacia la izquierda
    if (y - 1 >= 0 && (laberinto[x][y - 1] == ' ' || laberinto[x][y - 1] == 'B')) {
        if (calcularRutas(laberinto, x, y - 1)) return 1;
    }

    laberinto[x][y] = ' ';
    return 0;
}
