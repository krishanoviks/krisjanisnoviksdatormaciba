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

# 5. LD Bubble sort

```
#include <stdio.h>
#include <string.h>

void swap(char *xp, char *yp)
{
  char temp = *xp;
  *xp = *yp;
  *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(char arr[], int n)
{
int i, j;
for (i = 0; i < n-1; i++)

  // Last i elements are already in place
  for (j = 0; j < n-i-1; j++)
    if (arr[j] > arr[j+1] && arr[j+1] != 10) //pedejo simbolu '\0' = 10 nenem vera
      swap(&arr[j], &arr[j+1]);
}

/* Function to print an array */
void printArray(char arr[], int size)
{
  int i;
  for (i=0; i < size; i++) printf("%c", arr[i]);
  printf("\n");
  for (i=0; i < size; i++) printf("%d, ", arr[i]);
  printf("\n");
}

/* MODAS APREKINASANA */
void mode(char * str)
{
int freq[128]= {0};
int max=0;
for (int i=0; str[i] != 10; i++) freq[str[i]] +=1;
for (int i=0; i<128; i++) if (freq[i]>max) max = freq[i];
if (max < 2) printf("Nav modu\n");
else
{
  printf("Moda(s):\n");
  for(int i=0; i<128; i++)
    if (freq[i] == max) printf("'%c'\n",i);
}
}

// Driver program to test above functions
int main()
{
  printf("Ievadiet simbolu virkni:");
  char arr[256];
  fgets(arr, sizeof(arr), stdin);

  FILE * pFile;
  pFile = fopen("histogram.txt","w");
  fprintf(pFile,"# virkne: %s",arr);

  int n = strlen(arr);
  bubbleSort(arr, n);

  printf("Sakartota virkne: \n");
  printArray(arr, n-1); //neprinte pedejo simbolu jo tas ir '\0';

  printf("\nMinimala vertiba %d atbilst simbolam '%c'\n",arr[0],arr[0]);

  printf("\nMaksimala vertiba %d atbilst simbolam '%c'\n",arr[strlen(arr)-2],arr[strlen(arr)-2]); //n-2 jo skaitisana sakas no 0 nevis 1 un nenem vera pedejo simbolu '\0'
  printf("\n");

  mode(arr);
//MEDIANA
  if ((strlen(arr)-1) % 2 == 1)
    printf("\nMediana ir %d, kas atbilst simbolam '%c'\n",arr[(strlen(arr)/2)-1],arr[(strlen(arr)/2)-1]);
  else
  {
    char median = (arr[(strlen(arr)/2)-1]+arr[strlen(arr)/2]) / 2;
    printf("\nMediana ir videjais starp '%c' un '%c' = %d, kas atbilst simbolam '%c'\n",arr[(strlen(arr)/2)-1],arr[strlen(arr)/2],median,median);
  }

//AVERAGE
  long int sum = 0;
  for (int i=0; i<strlen(arr)-1; i++) sum+=arr[i];
  printf("\nVirknes videja vertiba = %d, kas atbilst simbolam '%c'\n",sum/(strlen(arr)-1),sum/(strlen(arr)-1));

//GNUPLOT HISTOGRAMMA
  int freq[128]= {0};
  for (int i=0; arr[i] != 10; i++) freq[arr[i]] +=1;
  for (int i=32; i<127; i++) fprintf(pFile,"\t%c\t%d\n",i,freq[i]); //sakam no redzamiem simboliem
  fclose(pFile);

  return 0;
}
```
##Izmantots string 'Krisjanis ir fors'
![bubblesort histogram](/ld/LD5/histogram.svg)
