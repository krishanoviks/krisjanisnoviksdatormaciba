
#include <stdio.h>

void main(){


char input,i,result;

printf("ievadi skaitli: ");
scanf("%d", &input);

for (i = 8; i >= 0; i-=1)
{
	result = input >> i;
	if (result & 1)
	printf("1");
	else printf("0");
}

printf("\n");


}
