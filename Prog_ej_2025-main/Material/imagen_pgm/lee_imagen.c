#include <stdio.h>

int main(){
    FILE *ent, *sal;
    char magica[5];
    char comen[100];
    int ancho, alto, grises, pixel, i, j, cont = 0;
    unsigned int pixeles[800][800];

    ent = fopen("Cartagena.pgm", "r");
    sal = fopen("Cartagena_1.pgm", "w"); 
    fgets(magica, 5, ent);
    fprintf(sal, "%s", magica);
    fgets(comen, 100, ent);
    fprintf(sal, "%s", comen);
    fscanf(ent, "%d", &ancho);
    fscanf(ent, "%d", &alto);
    fscanf(ent, "%d", &grises);   
    fprintf(sal, "%d %d\n%d\n", ancho, alto, grises); 
    for (i = 0; i < alto; i++){
        for (j = 0; j < ancho; j++){
            fscanf(ent, "%d", &pixel);
            fprintf(sal, "%d\n", pixel);
            pixeles[i][j] = pixel;
        }
    }

    fclose(ent);
    fclose(sal);
    return 0;
}