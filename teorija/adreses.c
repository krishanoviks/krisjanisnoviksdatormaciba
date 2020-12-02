#include <stdio.h>

int main(){

	int a=5;
	int *pa = &a; //norade uz int tipa mainigo ar a adresi

	printf("adreses vertiba pirms izmainam - %p\n",pa);
	printf("mainiga vertiba pirms izmainam - %d\n",a);

	test(pa);

	printf("adreses vertiba pec izmainam - %p\n",pa);
	printf("mainiga vertiba pec izmainam - %d\n",a);


	return 0;
}

void test(int *paa)
{

	printf("adreses vertiba no test - %p\n",paa);
	printf("mainiga vertiba no test - %d\n",*paa);
	*paa = *paa + 10;
}
