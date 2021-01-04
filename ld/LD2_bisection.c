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

//apmaina robezas ja pirma ir lielaka par otro
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
