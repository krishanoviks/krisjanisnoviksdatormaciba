//krisjanis noviks

#include <stdio.h>


unsigned long long ieprieksejais;
long long input;
char type;

void main(){

printf("ievadi skaitli ");
scanf("%lld",&input);
long long i = input;

printf("ievadi c prieks char, i prieks int vai l prieks long long ");
scanf("%s",&type);

if (type == 'c')
{
	unsigned char fact = 1;
	for (i;i >= 1;i-=1)
	{
		fact *= i;
		if (fact < ieprieksejais) break;
		ieprieksejais = fact;
	}
	if (i == 0) printf("%llu! = %hhu\n",input,fact);
	else printf("ar so datu tipu nevar\n");
}
else if (type == 'i')
{
	unsigned int fact = 1;
	for (i;i >= 1;i-=1)
	{
		fact *= i;
		if (fact < ieprieksejais) break;
		ieprieksejais = fact;
	}
	if (i == 0) printf("%llu! = %u\n",input,fact);
	else printf("ar so datu tipu nevar \n");
}
else if (type == 'l')
{
	unsigned long long fact = 1;
	for (i;i >= 1;i-=1)
	{
		fact *= i;
		if (fact < ieprieksejais) break;
		ieprieksejais = fact;
	}
	if (i == 0) printf("%llu! = %llu\n",input,fact);
	else printf("ar so datu tipu nevar");
}

else printf("ievadiet pareizi datu tipu, 'c' - char, 'i' - int, 'l' - long long\n");


} //for main
