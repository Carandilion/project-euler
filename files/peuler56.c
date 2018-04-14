#include <stdio.h>
#include <string.h>
#include <gmp.h>
char* bigexp(unsigned long long x,unsigned long long y){
  mpz_t result;
  mpz_init(result);
  mpz_ui_pow_ui(result,x,y);
  return(mpz_get_str(NULL,10,result));
}
int sumcharsstr(char* string) {
  int sum=0;
  char aux;
  for(int i=0;i<strlen(string);i++){
    aux=string[i];
    sum+= aux - '0';
  }
  return sum;
}
int main(int argc, char const *argv[]) {
  char *result;
  unsigned long long int i,j;
  int biggersum=0;
  int sumchars=0;
  for (i = 99; i > 1; i--) {
    for (j = 99; j > 1; j--) {
      result=bigexp(i,j);
      sumchars=sumcharsstr(result);
      if(sumchars > biggersum)
        biggersum=sumchars;
    }
  }
  printf("\n\n%i\n\n",biggersum);
  return 0;
}
