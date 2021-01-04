#include <stdio.h>
#include <string.h>

void swap(char *xp, char *yp)
{
  char temp = *xp;
  *xp = *yp;
  *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(char arr[], int n)
{
int i, j;
for (i = 0; i < n-1; i++)

  // Last i elements are already in place
  for (j = 0; j < n-i-1; j++)
    if (arr[j] > arr[j+1] && arr[j+1] != 10) //pedejo simbolu '\0' = 10 nenem vera
      swap(&arr[j], &arr[j+1]);
}

/* Function to print an array */
void printArray(char arr[], int size)
{
  int i;
  for (i=0; i < size; i++) printf("%c", arr[i]);
  printf("\n");
  for (i=0; i < size; i++) printf("%d, ", arr[i]);
  printf("\n");
}

/* MODAS APREKINASANA */
void mode(char * str)
{
int freq[128]= {0};
int max=0;
for (int i=0; str[i] != 10; i++) freq[str[i]] +=1;
for (int i=0; i<128; i++) if (freq[i]>max) max = freq[i];
if (max < 2) printf("Nav modu\n");
else
{
  printf("Moda(s):\n");
  for(int i=0; i<128; i++)
    if (freq[i] == max) printf("'%c'\n",i);
}
}

// Driver program to test above functions
int main()
{
  printf("Ievadiet simbolu virkni:");
  char arr[256];
  fgets(arr, sizeof(arr), stdin);

  FILE * pFile;
  pFile = fopen("histogram.txt","w");
  fprintf(pFile,"# virkne: %s",arr);

  int n = strlen(arr);
  bubbleSort(arr, n);

  printf("Sakartota virkne: \n");
  printArray(arr, n-1); //neprinte pedejo simbolu jo tas ir '\0';

  printf("\nMinimala vertiba %d atbilst simbolam '%c'\n",arr[0],arr[0]);

  printf("\nMaksimala vertiba %d atbilst simbolam '%c'\n",arr[strlen(arr)-2],arr[strlen(arr)-2]); //n-2 jo skaitisana sakas no 0 nevis 1 un nenem vera pedejo simbolu '\0'
  printf("\n");

  mode(arr);
//MEDIANA
  if ((strlen(arr)-1) % 2 == 1)
    printf("\nMediana ir %d, kas atbilst simbolam '%c'\n",arr[(strlen(arr)/2)-1],arr[(strlen(arr)/2)-1]);
  else
  {
    char median = (arr[(strlen(arr)/2)-1]+arr[strlen(arr)/2]) / 2;
    printf("\nMediana ir videjais starp '%c' un '%c' = %d, kas atbilst simbolam '%c'\n",arr[(strlen(arr)/2)-1],arr[strlen(arr)/2],median,median);
  }

//AVERAGE
  long int sum = 0;
  for (int i=0; i<strlen(arr)-1; i++) sum+=arr[i];
  printf("\nVirknes videja vertiba = %d, kas atbilst simbolam '%c'\n",sum/(strlen(arr)-1),sum/(strlen(arr)-1));

//GNUPLOT HISTOGRAMMA
  int freq[128]= {0};
  for (int i=0; arr[i] != 10; i++) freq[arr[i]] +=1;
  for (int i=32; i<127; i++) fprintf(pFile,"\t%c\t%d\n",i,freq[i]); //sakam no redzamiem simboliem
  fclose(pFile);

  return 0;
}

