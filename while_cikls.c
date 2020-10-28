// cikls for(sakuma vertibas;izteiksmei; darbibas){cikla bloks}


//while(){} parbaudis no sakuma
//do{} while() vienreiz izdaris un tad parbaudis

#include <stdio.h>
#include <math.h>

int main(){
 while(0)
 {
  printf("sis teksts netiks attelots\n");
 }
 while(1)
 {
  printf("sis teksts tiks bezgaligi attelots\n");
  break;
 }
 double a = 3.5e-1;
 double s = 0.5e-2;
  while(a <= 1.0)
 {
  printf("sis teksts tiks attelots\n");
  a = a + s;
 }

 double b, c, precision;

 for(b=0.35, c=0.05, precision = c/2; fabs(b-1.0 > precision); b+=c, c+=-.01){
 printf("a ir vienads ar %.20f vai ar peldoso punktu %e\n",b,b);
 }



 return 0;
}
