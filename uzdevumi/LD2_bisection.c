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

 printf("Vienadojums e^(-x) = %e\n",c);

 while((float)abs(b-a)>(float)d){
  k++;
  x = (double) (b+a)/2;
 printf("%le %le %le\n",a,b,x);
  if((exp(-a)-c)*(exp(-x)-c)<0) b = x;
  else a = x;
 }

 printf("x = %e\n",x);
 printf("iteraciju skaits = %d",k);


 return 0;
}
