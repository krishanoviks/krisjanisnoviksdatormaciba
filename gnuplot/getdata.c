#include <stdio.h>
#include <math.h>

int a,b,N;

double y,x;

void main(){

printf("Ievadiet robezu a:");
scanf("%d",&a);
printf("Ievadiet robezu b:");
scanf("%d",&b);
printf("Ievadiet punktu skaitu N:");
scanf("%d",&N);

//apmaina vietam ja pirma lielaka par otro
if (a>b)
{
a = a+b;
b = a-b;
a = a-b;
}


//exp(x)

//atver failu
FILE * pFile;
pFile = fopen ("myfile.txt","w");

//ieraksta faila
if (pFile!=NULL)
{
  for (int i=0; i<N; i++)
  {
    x=(double)a + (double)i*(b-a)/N;
    y = exp(x);
  fprintf(pFile,"%.3lf %.3lf\n",x,y); //parraksta visu un ievada rindinu
  }
  fclose (pFile);
}



}
