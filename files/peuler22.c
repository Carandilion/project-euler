#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void freepa(char** array,int size){
  for(int i=0;i<size;i++)
    free(array[i]);
  free(array);
}
int compare (const void * a, const void * b ) {
    const char *pa = *(const char**)a;
    const char *pb = *(const char**)b;
    return strcmp(pa,pb);
}
int main(int argc, char const *argv[]) {
  FILE *namefile;
  char** names;
  names = malloc(5200 * sizeof *names);
  namefile = fopen("peuler22.txt","r");
  int count=0,sumaux;
  names[count] = malloc(20);
  while (fscanf(namefile, "\"%[^\"]\",", names[count]) != EOF) {
    count++;
    names[count] = malloc(20);
  }
  qsort(names,5164,sizeof(char *),compare);
  unsigned long long name_score[5164]={0};
  unsigned long long sumallscores=0;
  char ac;
  for (size_t i = 1; i <= 5163; i++) {
    for (size_t j = 0; j < strlen(names[i]); j++) {
      ac = names[i][j];
      name_score[i] = name_score[i] + ac - '@';
      }
    name_score[i] *= i;
  }
  for (size_t i = 1; i <= 5163; i++) {
    sumallscores+=name_score[i];
  }
  printf("\n%llu\n",sumallscores);
  freepa(names,5200);
  return 0;
}
