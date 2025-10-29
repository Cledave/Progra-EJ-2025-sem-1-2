#include <stdio.h>
#define FILAS 10
#define COLUMNAS 10
#define INICIOx 0
#define INICIOy 0

/* Matriz */
char laberinto[FILAS][COLUMNAS] = {
    {'A', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' '},
    {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' '},
    {' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' '},
    {' ', '#', '#', ' ', '#', ' ', '#', ' ', '#', ' '},
    {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' '},
    {'#', '#', '#', '#', '#', ' ', '#', ' ', '#', ' '},
    {' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' '},
    {' ', '#', '#', '#', '#', ' ', '#', ' ', '#', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', 'B'}}; //ES EL LABERINTO
// Prototipos de funciones
void mostrarlaberinto();
int calcularRutas(char laberinto[FILAS][COLUMNAS],int x,int y);
int resultadolab(char laberinto[FILAS][COLUMNAS]);

int main(){
    printf("----- dungeon of the dragon!!! ---\n");
    mostrarlaberinto();
    resultadolab(laberinto);
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
        return 1;   //CUANDO A LA META 'B', DEVUELVE 1
    }
    laberinto[x][y] = 'A'; //ANTES DE EMPEZAR CON LOS BUCLES, SE DEFINE X-Y COMO PUNTO INCIAL DEL LABERINTO
    
    if (x<0 || x>= FILAS || y<0 || y>= COLUMNAS) {
        return 0;                                               //PARA QUE NO SE SALGA DEL TABLERO      
    }
    //movimientos
    if ((laberinto[x + 1][y] == ' ' || laberinto[x + 1][y] == 'B')) { // si el espacio en x+1 esta ' '(libre) o se llego al destino 'B' envia true
        if (calcularRutas(laberinto, x + 1, y)){                      // vuelve al bucle (recursion) y los mismo de antes, basicamente es lo mismo en todas
            return 1;                                                 // es importante cuidar la sintaxis
        }
    }
    if ((laberinto[x - 1][y] == ' ' || laberinto[x - 1][y] == 'B')) { //Si no se cumple el if y de devuelve un false (0), se cambia a la proxima condicion
        if (calcularRutas(laberinto, x - 1, y)){
            return 1;
        }
    }
    if ((laberinto[x][y + 1] == ' ' || laberinto[x][y + 1] == 'B')) {
        if (calcularRutas(laberinto, x, y + 1)){
            return 1;
        }
    }
    if ((laberinto[x][y - 1] == ' ' || laberinto[x][y - 1] == 'B')) {
        if (calcularRutas(laberinto, x, y - 1)){
            return 1;
        }
    }
    laberinto[x][y] = ' '; //Es parte del backtracking, marca la casilla en la que se devuelve como vacia para dejarla  desmarcad
    return 0;
}
int resultadolab(char laberinto[FILAS][COLUMNAS]){
    if(calcularRutas(laberinto, INICIOx,INICIOy)){
        mostrarlaberinto();
    } else {
        printf("Sin camino\n");
    }
}