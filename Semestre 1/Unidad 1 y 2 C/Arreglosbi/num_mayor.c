#include <stdio.h>

int main(){
    int matriz [3][3] = {
        {10,20,30},
        {40,150,60},
        {70,80,90}
    };
    int a,b;
    int num_mayor = matriz[0][0];

    for (a = 0;a<3;a=a+1){
        for (b = 0;b<3;b=b+1){
            if (matriz[a][b]>num_mayor){
                num_mayor=matriz[a][b];
            }
        }
    }
    printf("%d",num_mayor);
    return(0);
}    