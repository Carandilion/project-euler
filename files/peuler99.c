#include <stdio.h>
#include <gmp.h>
#include <string.h>
char* bigexp(unsigned long long x,unsigned long long y){
  mpz_t result;
  mpz_init(result);
  mpz_ui_pow_ui(result,x,y);
  return(mpz_get_str(NULL,10,result));
}
int main(int argc, char const *argv[]) {
  FILE *file,*filewr;
  char *result;
  unsigned long long a,b;
  file = fopen("peuler99.txt","r");
  filewr = fopen("peuler99.result","w+");
  while (fscanf(file,"%llu%*c%llu",&a,&b) != EOF) {
    printf("\n%llu:%llu\n",a,b);
    result = bigexp(a,b);
    fprintf(filewr,"%.5s,%lu",result,strlen(result));
    fprintf(filewr,"\n");
  }
  printf("\nDone!\n");
  return 0;
}
