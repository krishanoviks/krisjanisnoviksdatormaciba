
#include <stdio.h>

main(){

 if(1){
  printf("teksts bus redzams jo 1!=0\n");
 }
 if(0){
  printf("teksts nebus redzams jo 0\n");
 }

 char a = 10;
 if(a==10){
  printf("teksts bus redzams jo a=10\n");
  printf("a = %d\n",a);
 } else {
  printf("ne mainiga vertiba nav 10\n");
  printf("a = %d\n",a);
 }

return 0;

}
