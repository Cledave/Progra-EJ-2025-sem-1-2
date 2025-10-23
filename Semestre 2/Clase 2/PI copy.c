 #include <stdio.h>
  #include <math.h>
 int main(){
//WALLIS:

    float res_prin;
    float total=0.0;
    for (int n=1;n<52;n=n+1){
        res_prin=(((2.0*n)/((2.0*n)-1.0))*((2.0*n)/((2.0*n)+1.0)));
        printf("%f\n",res_prin);
        printf("%f",res_prin);
    }
}
