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
