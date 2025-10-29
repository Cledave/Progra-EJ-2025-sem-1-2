/*Especificador de precisión*/
#include <stdio.h>
#define escribe printf
#define entero int
#define principal main
#define retornar return
#define inicio {
#define fin }    

entero principal ()inicio
    escribe ("%.4f\n",123.1234567);
    escribe ("%8d\n",1000);
    retornar 0;
fin