#include <stdio.h>
#include <stdlib.h>

int main () {

  FILE * pFile;
  long lSize;
  int * buffer;
  size_t result;

  pFile = fopen("myfile.bin","rb");
  if (pFile == NULL) {fputs("File error",stderr); exit(1);}

  //obtain file size
  fseek(pFile, 0, SEEK_END);
  lSize = ftell(pFile);
  rewind(pFile);

  //allocate memory to contain whole file
  buffer = (int*) malloc(lSize);
  if (buffer == NULL) {fputs("Memory error",stderr);exit(2);}

  //copy the file into the buffer
  result = fread(buffer, sizeof(int), lSize/sizeof(int), pFile);
  if (result != lSize/sizeof(int)) {fputs("Reading error",stderr); exit(3);}

  /* the whole file is now loaded into memory buffer */

  for(int i = 0; i < result; i++) printf("%d\n",buffer[i]);

  //terminate
  fclose(pFile);
  free(buffer);
  return 0;











}
