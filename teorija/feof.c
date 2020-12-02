#include <stdio.h>

int main(){

 FILE * pFile;
 char buffer [100];

 pFile = fopen{"myfile.txt", "r"};
 if (pfile == NULL)
 {
  perror("Error opening file");
  return 1;
 }

 while (!eof(pFile))
 {
  if (fgets(buffer, 100, pFile) == NULL) break;
  fputs(buffer,stdout);
 }

 fclose(pFile);


return 0;
}
