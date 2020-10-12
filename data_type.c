
#include <stdio.h>
#define A 11 //define konstanti kuru nevar mainit

void main(){
 char a = 10; //(definesana)
 //1. darbiba - (deklaresana) - ram atmina tiek ieveleta vieta viena char tipa datu mainiga glabasanai
 //si vieta ir viennozimigi sakedeta ar identifikatoru a
 //saskana ar char datu tipu vietas izmers ir 1 byte
 //kaa saja gadijuma izskatijas tas atminas apgabals: 1101 1001, vai 1000 0000 vai 0101 1111
 // char a
 // 2. darbiba - vertibas pieskirsana
 // a -> 0000 1010
 printf("Mainiga a vertiba ir: %d\n",a);
 printf("Konstantes A vertiba ir: %d\n",A);
 // A = 126 NEVAR MAINIT KONSTANTES KODA LAIKA
 char mans_mainigais = 45; // centisimies izmantot mneimoniskus nosaukumus
 a = 100;

 printf("Mainiga a vertiba ir: %d\n",a);
 printf("Mainiga a vertiba ir: 0x%x\n",a);
 printf("Mainiga a vertiba ir: %o(oct)\n",a);
 printf("Mainiga a vertiba ka burts ir: %c\n",a);
 a = 'l';
printf("Mainiga a vertiba ka burts ir: %c\n",a);

 //1 byte - 256 numbers
 // => without sign 0..256
 // => with sign -128 ... 0 ... 127

 //mainiga data tipu c valoda nedrikst mainit

 unsigned char b = 200;
 printf("Mainiga b vertiba ir: %d\n",b);

 int c;
 printf("int datu tipa izmers baitos ir: %ld\n",sizeof(c));

 //soreiz int atbilst 4 baitiem (32 bit)
 // => without sign 0 ... (2^32 -1)
 // => with sign -(2^31) ... 0 ... (2^31 -1)

//----------------------------------------------------------------

 float d = 6.5;
 printf("float datu tipa skaitla attelosana %.2f\n", d);
 char input;
 printf("ievadi vienu burtu");
 scanf("%c"&input);
 printf("tu esi ievadijis simbolu: %c\n",input);
}
