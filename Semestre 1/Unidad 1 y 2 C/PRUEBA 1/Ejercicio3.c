#include <stdio.h> 
#include <string.h> 
#include <ctype.h>  
#include <stdlib.h> 
//no se porque no funciona :)

int main(){
    char frase[100];
    fgets(frase, 100, stdin);
    int cero    = 0;
    int uno     = 0;
    int dos     = 0;
    int tres    = 0;
    int cuatro  = 0;
    int cinco   = 0;
    int seis    = 0;
    int siete   = 0;
    int ocho    = 0;
    int nueve   = 0;
    int espaci  = 0;
    int otros = 0;
    int i;
    int longitud_frase = strlen(frase);

    for (i = 0; i < longitud_frase; i++ ){
        if (frase[i]=='0') { 
            cero ++;
        }
        else if (frase[i]=='1') { 
            uno ++;
        }
        else if (frase[i]=='2') { 
            dos ++;
        }      
        else if (frase[i]=='3') { 
            tres ++;
        }
        else if (frase[i]=='4') { 
            cuatro ++;
        }
        else if (frase[i]=='5') {
            cinco ++;
        }
        else if (frase[i]=='6') {
            seis ++;
        }
        else if (frase[i]=='7') {
            siete ++;
        }
        else if (frase[i]=='8') {
            ocho ++;
        }
        else if (frase[i]=='9') {
            nueve ++;
        }
        else if (frase[i]==' ') {
            espaci++;
        }
        else {
            otros++;
        }
    }
    
    printf("0:%d\n",cero);
    printf("1:%d\n",uno);
    printf("2:%d\n", dos);
    printf("3:%d\n", tres);
    printf("4:%d\n", cuatro);
    printf("5:%d\n", cinco);
    printf("6:%d\n", seis);
    printf("7:%d\n", siete);
    printf("8:%d\n", ocho);
    printf("9:%d\n", nueve);
    printf("espacios:%d\n",espaci);
    printf("otros:%d\n", (otros-1));

    return 0;
}