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
void mostrarLaberinto();
void calcularRutas(char laberinto[FILAS][COLUMNAS],int x,int y);

int main(){
    printf("----- BUSCANDO EL CAMINO DEL LABERINTO RECURSIVO ---\n");
    printf("Buscando el camino desde A hasta B \n");
    mostrarLaberinto();
    calcularRutas(laberinto, INICIOx,INICIOy);
}

//funciones

void mostrarLaberinto(){
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
void calcularRutas(laberinto, int x,int y){






    
    }
