#include <stdio.h>
#define N 5

int main()
{

	int array_a[N];
	int array_b[]={1,2,3};
	int array_c[N]={4,5,6};
	int array_d[3][2] = {{1,2},{3,4},{5,6}};


	printf("b masiva adrese %p\n",array_b);
	printf("b masiva pirma (0.) elemendta vertiba %d un adrese %p\n",array_b[0],&array_b[0]);
	printf("b masiva otra (1.) elemendta vertiba %d un adrese %p\n",*(array_b+1),array_b+1);








}
