#include <stdio.h>

int main(){
    int matriz [3][3] = {
        {10,20,30},
        {40,50,60},
        {70,80,90}
    };
    int suma = 0;
    float prom = 0.0;
    int a,b;
    
    for (a = 0;a<3;a=a+1){
        for (b = 0;b<3;b=b+1){
            suma = suma + matriz[a][b];
        }
    }
    prom = suma/9.0;
    printf ("suma total: %d\n promedio: %.1f", suma, prom);
    return(0);

}    