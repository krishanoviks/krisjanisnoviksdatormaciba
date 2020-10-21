
#include <stdio.h>

int main(){

int a;
int b;
int c;
int d;

printf("Ievadi pirmo skaitli: ");
scanf("%d",&a);
printf("Ievadi otro skaitli: ");
scanf("%d",&b);
printf("ievadi treso skaitli: ");
scanf("%d",&c);
printf("ievadi '1', lai sakartotu augosa seciba vai '0', lai sakartotu dilstosi:  ");
scanf("%d",&d);
printf("\n");

if (d == 1){
if (a > b && a > c){
 if(b > c) printf("%d %d %d\n",c,b,a); else printf("%d %d %d\n",b,c,a);
}
if (b > a && b > c){
 if(a > c) printf("%d %d %d\n",c,a,b); else printf("%d %d %d\n",a,c,b);
}
if (c > b && c > a){
 if(a > b) printf("%d %d %d\n",b,a,c); else printf("%d %d %d\n",a,b,c);
}
} else if (d == 0){
if (a > b && a > c){
 if(b > c) printf("%d %d %d\n",a,b,c); else printf("%d %d %d\n",a,c,b);
}
if (b > a && b > c){
 if(a > c) printf("%d %d %d\n",b,a,c); else printf("%d %d %d\n",b,c,a);
}
if (c > b && c > a){
 if(a > b) printf("%d %d %d\n",c,a,b); else printf("%d %d %d\n",c,b,a);
}
} else printf("ok\n");

return 0;
}
