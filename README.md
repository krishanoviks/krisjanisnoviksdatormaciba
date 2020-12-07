1. LD taylor series e^(-x)

#include <stdio.h>
#include <math.h>

long double approx = 1,x,a = 1.0;
int k = 1;

int main(){

 printf("ievadiet x: ");
 scanf("%Le",&x);


 while(k<1000)
 {
   a = a* (long double) (-x)/k;
   approx += a;
   k++;
 }

 // zimesana
 printf("               1000              \n");
 printf("               _____         k   \n");
 printf("               \\         (-x)    \n");
 printf("exp(-%.2Lf) =   >      _______   \n",x);
 printf("               /____      k!     \n");
 printf("               k = 0             \n");

 printf("                          (-x)\n");
 printf("rekursijas reizinatajs = _____\n");
 printf("                           k  \n");

 printf("funkcija defineta visas realas x vertibas\n");
 printf("pec teilora rindas aprekinatais e^(-%.2Lf) = %.20LE\n",x,approx);
 printf("pec exp(-x) aprekinatais e^(-%.2Lf) = %.20LE\n",x,exp(-x));



 return 0;
}
