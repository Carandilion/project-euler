#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
const char* strsort(char* string) {
  char aux;
  int i,j;
  for (i = 0; i < strlen(string)-1 ; i++) {
    for (j = i+1; j < strlen(string); j++) {
      if(string[i]>string[j]){
        aux=string[i];
        string[i]=string[j];
        string[j]=aux;
      }
    }
  }
  return string;
}
int main(int argc, char const *argv[]) {
  int n=1;
  char *n_to_string , *n_to_string2;
  n_to_string  =(char*)malloc(100);
  n_to_string2 =(char*)malloc(100);
  do {
    sprintf(n_to_string,"%i",n);
    sprintf(n_to_string2,"%i",6*n);
    if(strcmp (strsort(n_to_string) , strsort(n_to_string2) ) ==0){
      sprintf(n_to_string2,"%i",5*n);
      if(strcmp (strsort(n_to_string) , strsort(n_to_string2) ) ==0 ){
        sprintf(n_to_string2,"%i",4*n);
        if(strcmp (strsort(n_to_string) , strsort(n_to_string2) ) ==0){
          sprintf(n_to_string2,"%i",3*n);
          if(strcmp (strsort(n_to_string) , strsort(n_to_string2) ) ==0){
            sprintf(n_to_string2,"%i",2*n);
            if(strcmp (strsort(n_to_string) , strsort(n_to_string2) ) ==0){
              printf("\n\nFound at: %i.\n\n",n);
              break;
            }
          }
        }
      }
    }
    n++;
  } while(true);
  return 0;
}
