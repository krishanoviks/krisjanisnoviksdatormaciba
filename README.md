# 1. LD taylor series e^(-x)
```
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
```

# 2.LD bisection method

```
#include <stdio.h>
#include <math.h>

double a,b,c,d,x;
int k;

int main(){

 printf("Ievadiet a vertibu:");
 scanf("%le",&a);
 printf("Ievadiet b vertibu:");
 scanf("%le",&b);
 printf("Ievadiet c vertibu:");
 scanf("%le",&c);
 printf("Ievadiet precizitati:");
 scanf("%le",&d);

 if (a>b){
  a = a+b;
  b = a-b;
  a = a-b;
 }

 if ((exp(-a)-c) * (exp(-b)-c) > 0){
  printf("saja apgabala saknu nav\n");
  return 1;
}

 printf("Vienadojums e^(-x) = %e\n",c);

 while((float)abs(b-a)>(float)d){
  k++;
  x = (double) (b+a)/2;
  if((exp(-a)-c)*(exp(-x)-c)<0) b = x;
  else a = x;
 }

 printf("x = %e\n",x);
 printf("iteraciju skaits = %d\n",k);

 return 0;
}
```

![alt text](/gnuplot/output.svg)
