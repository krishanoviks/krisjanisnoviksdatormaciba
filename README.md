# funkcija e^(-x)
![exp(-x) graph](/gnuplot/output.svg)

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
# 3.LD derivative

```
#include <math.h>
#include <stdio.h>

double a,b,delta_x,x;

double fd_numerical(double x)
{
return (exp(-(x+delta_x))-exp(-x))/delta_x;
}

double sd_numerical(double x)
{
return (fd_numerical(x+delta_x)-fd_numerical(x))/delta_x;
}

int main()
{
  printf("ievadiet a robezu:");
  scanf("%lf",&a);
  printf("ievadiet b robezu:");
  scanf("%lf",&b);
  printf("ievadiet precizitati:");
  scanf("%lf",&delta_x);


  printf("SKAITLISKA METODE\n");
  x = a;
  FILE * pFile;
  pFile = fopen("derivative.dat","w");
  while(x < b)
  {
    fprintf(pFile,"%10.2f\t%10.2f\t%10.2f\t%10.2f\t%10.2f\t%10.2f\n",x,exp(-x),fd_numerical(x),sd_numerical(x),-exp(-x),exp(-x));
    printf("%10.2f\t%10.2f\t%10.2f\t%10.2f\n",x,exp(-x),fd_numerical(x),sd_numerical(x));
    x+=delta_x;
  }
  fclose(pFile);

  printf("\nANALITISKA METODE\n");
  x=a;
  while(x < b)
  {
    printf("%10.2f\t%10.2f\t%10.2f\t%10.2f\n",x,exp(-x),-exp(-x),exp(-x));
    x+=delta_x;
  }

  return 0;
}
```
![derivative graph](/ld/LD3/output.svg)

# 4.LD integral

```
#include <math.h>
#include <stdio.h>

double a,b,sum,delta,integr1,integr_ta,integr_tr,integr_Si,h;
int n=4,k;

double f(double x){
 return exp(-x);
}

int main()
{
 printf("ievadiet a vertibu:");
 scanf("%lf",&a);
 printf("ievadiet b vertibu:");
 scanf("%lf",&b);
 printf("ievadiet precizitati:");
 scanf("%lf",&delta);

 integr_ta=fabs(b-a)*(f(a)+f(b))/n;
 while(fabs(integr_ta-integr1)>delta)
 {
  n*=2;
  h=fabs(b-a)/n;
  integr1=integr_ta;
  integr_ta=0.;
  for(k = 0; k < n; k++ ) integr_ta += h*f(a+(k+0.5)*h);
 }
 printf("integrala vertiba ar taisnsturiem: %.6lf\n",integr_ta);

 n=2;
 integr1=0;
 h = fabs(b-a)/n;
 integr_tr=(h/2)*(f(a)+f(b)+2*f(a+h));

 while(fabs(integr_tr-integr1)>delta)
 {
  integr1=integr_tr;
  n*=2;
  h=fabs(b-a)/n;
  for(k = 1; k < n; k++ ) sum +=f(a+k*h);
  integr_tr = (h/2)*(f(a)+f(b)+2*sum);
 }
 printf("integrala vertiba ar trapecem: %.6lf\n",integr_tr/2);
 //es nezinu kapec bet rezultats sanak 2 reiz lielaks tapec es vel izdalu ar 2

 n=2;
 integr1=0;
 h=fabs(b-a)/n;
 integr_Si=(h/3)*(f(a)+f(b)+4*f(a+h));
 sum =0;

 while(fabs(integr_Si-integr1)>delta)
 {
   integr1=integr_Si;
   n*=2;
   h=fabs(b-a)/n;
   for(k = 1; k < n; k++ )
   {
     if (k % 2 == 0){
       sum +=2.*f(a+k*h);
     }
     else {
       sum += 4.*f(a+k*h);
     }
   }
   integr_Si = (h/3)*(f(a)+f(b)+sum);
 }
 printf("integrala vertiba ar Simpsona metodi: %.6lf\n",integr_Si/2);
 //es nezinu kapec bet rezultats sanak 2 reiz lielaks tapec es vel izdalu ar 2


 return 0;
}
```
![wolframalpha screenshot](/ld/LD4/Screenshot_from_2020-12-23_16-11-01.png)
![integral graph](/ld/LD4/output.png)

