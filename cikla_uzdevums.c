
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){

long input;
char cinput;
long long linput,fact;
int iinput;


printf("ievadiet veselu skaitli: ");
scanf("%ld",input);


char type;
printf("ievadiet datu tipu(char, int vai long): ");


scanf("%c",&type);
scanf("%c",&type);


if (type == 'c')
{
	printf("ooga\n");

	while((char)input>=1){
		fact = (char)input * (char)fact;
		input -= 1;
	}
}


printf("faktorialis = %c",fact);





return 0;
}
