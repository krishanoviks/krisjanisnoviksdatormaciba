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

//taisnstura metode
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


//trapecu metode
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

//Simpsona metode
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
