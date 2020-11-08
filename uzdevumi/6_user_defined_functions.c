// Krisjanis Noviks

#include <stdio.h>
#include <string.h>

void func1() //pasaka cik dienas lidz sestdienai
{
int day;
printf("kada sodien ir diena (ievadi skaitli 1-7): ");
scanf("%d",&day);
if (day > 7) day = day % 7;
day = 6 - day;
printf("ir vel %d dienas lidz sestdienai\n",day);
}

void func2(int input) //printe binaro kodu argumentam
{
int result,i;
for (i = 32; i >= 0; i -= 1)
{
	result = input >> i;
	if (result & 1) printf("1");
	else printf("0");
}
printf("\n");
}

long long func3(char i) //izvada faktoriali argumentam
{
long long fact = 1,ieprieksejais;
for (i;i>=1;i-=1) fact *=i;
return fact;
}

double func4()
{
double e=1;
for (int i = 1;i<=1000;i+=1) e *= 1001.0/1000.0;
return e;
}


int main()
{

func1();

func2(1006);

long long a = func3(10);
printf("%lli\n",a);

float e = func4();
printf("e = %.4f\n",e);
return 0;
}
