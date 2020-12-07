#include <stdio.h>
#include <math.h>

long double approx = 1,x,a = 1.0,pirmspedejais;
int k;

int main(){

 printf("ievadiet x: ");
 scanf("%Le",&x);


 while(k<1000)
 {
   pirmspedejais = a;
   k++;
   a = a* (long double) (-x)/k;
   approx += a;
 }

 // zimesana
 printf("               1000              \n");
 printf("               _____         k   \n");
 printf("               \\         (-x)    \n");
 printf("exp(-%.2Lf) =   >      _______   \n",x);
 printf("               /____      k!     \n");
 printf("               k = 0             \n");

 printf("\n                          (-x)\n");
 printf("rekursijas reizinatajs = _____\n");
 printf("                           k  \n");


 printf("\npedejais loceklis = %Le\n",a);
 printf("pirmspedejais loceklis = %Le\n",pirmspedejais);
 printf("\nfunkcija defineta visas realas x vertibas\n");
 printf("\npec teilora rindas aprekinatais e^(-%.2Lf) = %.50LE\n",x,approx);
 printf("pec exp(-x) aprekinatais e^(-%.2Lf) = %.50LE\n",x,exp(-x));



 return 0;
}
