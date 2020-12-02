#include <stdio.h>
#include <string.h>
#define N 80

int main()
{
	char key[] = "apple";
	char buffer[N];
	do {
		printf("guess my favourite fruit: ");
		fflush(stdout);
		scanf("%79s",buffer);
	} while (strcmp (key,buffer) != 0 );

	puts(" Correct answer!");
	return 0;


}
