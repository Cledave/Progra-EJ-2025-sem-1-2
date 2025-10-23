#include <stdio.h>

int main(){
    //Introducir los cuatro numeros
    int pri;
    int seg;
    int ter;
    int cua;
    printf("Ingresa el numero completo por partes.\n");
    printf("Ingresa primer numero (miles):\t");
    scanf("%d",&pri);
    if (pri<=0||pri>=10){
        printf("Rango invalido\nReingrese:\t");
        scanf("%d",&pri);
    }
    printf("Ingresa segundo numero (centenas):\t");
    scanf("%d",&seg);
    if (seg<0||seg>=10){
        printf("Rango invalido\nReingrese:\t");
        scanf("%d",&seg);
    }
    printf("Ingresa tercer numero (decenas):\t");
    scanf("%d",&ter);
    if (ter<0||ter>=10){
        printf("Rango invalido\nReingrese:\t");
        scanf("%d",&ter);
    }
    printf("Ingresa cuarto numero (unidades):\t");
    scanf("%d",&cua);
    if (cua<0||cua>=10){
        printf("Rango invalido\nReingrese:\t");
        scanf("%d",&cua);
    }

    int numero = (pri*1000)+(seg*100)+(ter*10)+(cua);
    int menor_a_mayor;
//pri
    if (pri<=seg && seg<=ter && ter<=cua){
        menor_a_mayor = pri*1000 + seg*100 + ter*10 + cua;
    }
    if (pri<=seg && seg<=cua && cua<=ter){
        menor_a_mayor = pri*1000 + seg*100 + cua*10 + ter;
    }
    if (pri<=ter && ter<=seg && seg<=cua){
        menor_a_mayor = pri*1000 + ter*100 + seg*10 + cua;
    }
    if (pri<=ter && ter<=cua && cua<=seg){
        menor_a_mayor = pri*1000 + ter*100 + cua*10 + seg;
    }
    if (pri<=cua && cua<=seg && seg<=ter){
        menor_a_mayor = pri*1000 + cua*100 + seg*10 + ter;
    }
    if (pri<=cua && cua<=ter && ter<=seg){
        menor_a_mayor = pri*1000 + cua*100 + ter*10 + seg;
    }
//Seg
    if (seg<=pri && pri<=ter && ter<=cua){
        menor_a_mayor = seg*1000 + pri*100 + ter*10 + cua;
    }
    if (seg<=pri && pri<=cua && cua<=ter){
        menor_a_mayor = seg*1000 + pri*100 + cua*10 + ter;
    }
    if (seg<=ter && ter<=pri && pri<=cua){
        menor_a_mayor = seg*1000 + ter*100 + pri*10 + cua;
    }
    if (seg<=ter && ter<=cua && cua<=pri){
        menor_a_mayor = seg*1000 + ter*100 + cua*10 + pri;
    }
    if (seg<=cua && cua<=pri && pri<=ter){
        menor_a_mayor = seg*1000 + cua*100 + pri*10 + ter;
    }
    if (seg<=cua && cua<=ter && ter<=pri){
        menor_a_mayor = seg*1000 + cua*100 + ter*10 + pri;
    }
//ter
    if (ter<=pri && pri<=seg && seg<=cua){
        menor_a_mayor = ter*1000 + pri*100 + seg*10 + cua;
    }
    if (ter<=pri && pri<=cua && cua<=seg){
        menor_a_mayor = ter*1000 + pri*100 + cua*10 + seg;
    }
    if (ter<=seg && seg<=pri && pri<=cua){
        menor_a_mayor = ter*1000 + seg*100 + pri*10 + cua;
    }
    if (ter<=seg && seg<=cua && cua<=pri){
        menor_a_mayor = ter*1000 + seg*100 + cua*10 + pri;
    }
    if (ter<=cua && cua<=pri && pri<=seg){
        menor_a_mayor = ter*1000 + cua*100 + pri*10 + seg;
    }
    if (ter<=cua && cua<=seg && seg<=pri){
        menor_a_mayor = ter*1000 + cua*100 + seg*10 + pri;
    }
//Cua
    if (cua<=pri && pri<=seg && seg<=ter){
        menor_a_mayor = cua*1000 + pri*100 + seg*10 + ter;
    }
    if (cua<=pri && pri<=ter && ter<=seg){
        menor_a_mayor = cua*1000 + pri*100 + ter*10 + seg;
    }
    if (cua<=seg && seg<=pri && pri<=ter){
        menor_a_mayor = cua*1000 + seg*100 + pri*10 + ter;
    }
    if (cua<=seg && seg<=ter && ter<=pri){
        menor_a_mayor = cua*1000 + seg*100 + ter*10 + pri;
    }
    if (cua<=ter && ter<=pri && pri<=seg){
        menor_a_mayor = cua*1000 + ter*100 + pri*10 + seg;
    }
    if (cua<=ter && ter<=seg && seg<=pri){
        menor_a_mayor = cua*1000 + ter*100 + seg*10 + pri;
    }
    //el mayor a menor seria el menor a mayor peor al revez

    int mayor_a_menor = 0;
    int menor_a_mayor_2 = menor_a_mayor;
    while (menor_a_mayor_2>0){
        mayor_a_menor = mayor_a_menor*10 + menor_a_mayor_2%10;
        menor_a_mayor_2 = menor_a_mayor_2/10;
    }
    /*
    printf("%d",menor_a_mayor);
    printf("\n");
    printf("%d",mayor_a_menor);
    */
















}