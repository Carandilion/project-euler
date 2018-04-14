#include <stdio.h>
#include <gmp.h>
char* bigjohn(void){
  mpz_t resulta,resultb;
  mpz_init(resulta);
  mpz_init(resultb);
  mpz_ui_pow_ui(resulta,2,7830457);
  mpz_mul_ui(resultb,resulta,28433);
  mpz_add_ui(resulta,resultb,1);
  return(mpz_get_str(NULL,10,resulta));
}
int main(int argc, char const *argv[]) {
  printf("\n\n%s\n\n",bigjohn());
}
