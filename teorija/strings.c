#include <stdio.h>
#define N 4


int main()
{

	char rinda1[N] = "abc";
	char rinda2[] = {'d','e','f'};
	char rinda3[] = "ghijk";
	char *rinda4 = "lmnop";

printf("simbolu rindas izmers bytes - %lu un simbolos(elementos) - %lu\n",sizeof(rinda1),sizeof(rinda1)/sizeof(char));
printf("simbolu rindas izmers bytes - %lu un simbolos(elementos) - %lu\n",sizeof(rinda2),sizeof(rinda2)/sizeof(char));
printf("simbolu rindas izmers bytes - %lu un simbolos(elementos) - %lu\n",sizeof(rinda3),sizeof(rinda3)/sizeof(char));
printf("simbolu rindas izmers bytes - %lu un simbolos(elementos) - %lu\n",sizeof(rinda4),sizeof(rinda4)/sizeof(char));

	for(int i = 0; i<N; i++)
	{
		printf("rinda1 %d. simbola dec kods - %d\n",i,rinda1[i]);
	}











}
