/* fopen example */
#include <stdio.h>
int main ()
{
  FILE * pFile;
  pFile = fopen ("myfile.txt","w");
  if (pFile!=NULL)
  {
    fputs ("fopen example\n",pFile); //parraksta visu un ievada rindinu
    fclose (pFile);
  }
  return 0;
}
