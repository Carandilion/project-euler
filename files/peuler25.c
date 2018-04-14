#include <stdio.h>
#include <gmp.h>
int main(void){
  mpz_t fib;
  mpz_init(fib);
  unsigned int i=1;
  do {
    mpz_fib_ui(fib,i);
    i++;
  } while(mpz_sizeinbase(fib,10)<1000);
  printf("Index %i.\n\nValue: %s.\n\n",i,mpz_get_str(NULL,10,fib));
  mpz_clear(fib);
}
