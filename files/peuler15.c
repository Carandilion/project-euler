#include "stdio.h"
#include "gmp.h"
#define line 20
#define row 20

// unsigned long long fat(unsigned long long x){   PARA LINHAS E COLUNAS EM QUE A SOMA É MAIOR QUE 20! É NECESSÁRIO USAR GMP OU SOLUÇÃO PARECIDA.
//   if(x==1)
//     return 1;
//   else
//     return x*fat(x-1);
// }

void path(int l,int c){
  mpz_t fatlc,fatl,fatc,answer,temp;
  unsigned int i;
  mpz_init_set_str(fatlc,"1",10);
  mpz_init(temp);
  for(i=2;i<=l+c;i++){
    mpz_set_ui(temp,i);
    mpz_mul(fatlc,fatlc,temp);
  }
  mpz_init_set_str(fatl,"1",10);
  for(i=2;i<=l;i++){
    mpz_set_ui(temp,i);
    mpz_mul(fatl,fatl,temp);
  }
  mpz_init_set_str(fatc,"1",10);
  for(i=2;i<=c;i++){
    mpz_set_ui(temp,i);
    mpz_mul(fatc,fatc,temp);
  }
  mpz_mul(temp,fatl,fatc);
  mpz_init_set_str(answer,"0",10);
  mpz_cdiv_q(answer,fatlc,temp);
  printf("\n\n%s paths.\n\n",mpz_get_str(NULL, 10, answer));

}

int main(int argc, char const *argv[]) {
  int map[line][row];
  unsigned long long counter,n,k;
  for (size_t i = 0; i < line; i++) {
    printf("\n\n");
    for (size_t j = 0; j < row; j++) {
      printf("[_] ");
    }
  }
  printf("\n\n");
  // counter=(fat(line+row))/(fat(line)*fat(row));      
  // printf("\n\n %llu paths.\n\n",counter);
  path(line,row);
  return 0;
}
