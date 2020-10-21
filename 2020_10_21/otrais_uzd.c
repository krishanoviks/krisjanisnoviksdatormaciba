
#include <stdio.h>

int main(){

char a,b,c;
int d;

printf("Ievadi pirmo burtu: ");
scanf("%s",&a);
printf("Ievadi otro burtu: ");
scanf("%s",&b);
printf("ievadi treso burtu: ");
scanf("%s",&c);
printf("ievadi '1', lai sakartotu augosa seciba vai '0', lai sakartotu dilstosi:  ");
scanf("%d",&d);
if (d == 1){ //augosa seciba
if (a > b && a > c){
 if(b > c) printf("%c %c %c\n",c,b,a); else printf("%c %c %c\n",b,c,a);
}
if (b > a && b > c){
 if(a > c) printf("%c %c %c\n",c,a,b); else printf("%c %c %c\n",a,c,b);
}
if (c > b && c > a){
 if(a > b) printf("%c %c %c\n",b,a,c); else printf("%c %c %c\n",a,b,c);
}
} else if (d == 0){ //dilstosa seciba
if (a > b && a > c){
 if(b > c) printf("%c %c %c\n",a,b,c); else printf("%c %c %c\n",a,c,b);
}
if (b > a && b > c){
 if(a > c) printf("%c %c %c\n",b,a,c); else printf("%c %c %c\n",b,c,a);
}
if (c > b && c > a){
 if(a > b) printf("%c %c %c\n",c,a,b); else printf("%c %c %c\n",c,b,a);
}
} else printf("ok\n");

return 0;
}
