#include <stdio.h>
#include <gmp.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  mpz_t bigjohn,base;
  unsigned long int expo=1000;
  mpz_init(bigjohn);
  mpz_init_set_str(base,"2",10);
  mpz_pow_ui(bigjohn,base,expo);

  char sbigjohn[strlen(mpz_get_str(NULL,10,bigjohn))];
  strcpy(sbigjohn,mpz_get_str(NULL,10,bigjohn));

  int sum=0;
  char digit;

  for(int i=0;i<strlen(sbigjohn);i++){
    digit=sbigjohn[i] - '0';
    sum+=digit;
  }
  printf("\n\n%i\n\n",sum);
  return 0;
}
