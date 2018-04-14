#include <stdio.h>
#include <gmp.h>
#include <string.h>
void bigfat(int x){
  int sumchars=0;
  mpz_t result,temp;
  mpz_init(temp);
  mpz_init_set_str(result,"1",10);
  for(size_t i=2;i<=x;i++){
    mpz_set_ui(temp,i);
    mpz_mul(result,result,temp);
  }
  printf("\nRESULTADO:\n%s\n\n",mpz_get_str(NULL, 10, result));
  char str[strlen(mpz_get_str(NULL,10,result))];
  strcpy(str,mpz_get_str(NULL,10,result));
  char digit;
  for (size_t i = 0; i < strlen(str); i++) {
    digit=str[i]-'0';
    sumchars+=digit;
  }
  printf("\n\nSOMA DOS CHARS: %i\n\n",sumchars);
}
int main(int argc, char const *argv[]) {
  bigfat(100);
  return 0;
}
