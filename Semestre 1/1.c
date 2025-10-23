#include <stdio.h>
int main(){


    int voto[11];
    int playa=0;
    int montaña=0;
    int parque=0;
    int contador=0;
    
    for (int a=0;a<12;a=a+1){
        printf("Ingrese su voto:\t");
        scanf("%d",&voto[a]);
        if (voto[a]==1){
            playa=playa+1;
        } else if (voto[a]==2){
            montaña=montaña+1;
        } else if (voto[a]==3){
            parque=parque+1;
        }
    }
    printf("\n");
    printf("Playa:   %d votos\n",playa);
    printf("Montana: %d votos\n",montaña);
    printf("Parque:  %d votos\n",parque);
    return(0);
}

//11 ES 12 VERDAD? POR EL 0