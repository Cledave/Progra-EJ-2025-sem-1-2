 #include <stdio.h>
  #include <math.h>

 int main(){
//LEIBNIZ:
    float res_prin;
    float total=0.0;
    for (int n=0;n<100000000000;n=n+1){
        res_prin=(pow((-1),n))/((2*n)+1);
        total=res_prin+total;        
    }   
    printf("leibniz, 50 ciclos=%f\n",total);
    printf("PI leibniz=%f",total*4);
    printf("\n"); 
//WALLIS:
    float res_prin_W;
    float total_W=1.0;
    for (int n=1;n<100000000000;n=n+1){
        res_prin_W=(((2.0*n)/((2.0*n)-1.0))*((2.0*n)/((2.0*n)+1.0)));
        total_W=res_prin_W*total_W;
    }
    printf("WALLIS, 50 ciclos=%f\n",total_W); 
    printf("PI WALLIS=%f",total_W*2);

}