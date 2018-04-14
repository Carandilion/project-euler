#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[]) {
  unsigned long long sum=0;
  char *unidade[21]=
  {"","one","two","three","four","five",
  "six","seven","eight","nine","ten",
  "eleven","twelve","thirteen","fourteen","fifteen",
  "sixteen","seventeen","eighteen","nineteen","twenty"};
  char *dezena[10]=
  {"","","twenty","thirty","forty",
  "fifty","sixty","seventy","eighty","ninety"};
  char *centena[10]={"","onehundred","twohundred","threehundred","fourhundred","fivehundred","sixhundred",
  "sevenhundred","eighthundred","ninehundred"};
  for (size_t c = 0; c < 10; c++) {
    for (size_t d = 0; d < 10; d++) {
      for (size_t u = 0; u < 10; u++) {
        if(d>=1 && d<2){
          printf("%s-%s\n",centena[c],unidade[u+10]);
          sum+=strlen(centena[c])+strlen(unidade[u+10]);
        }
        else{
          printf("%s-%s-%s\n",centena[c],dezena[d],unidade[u]);
          sum+=strlen(centena[c])+strlen(dezena[d])+strlen(unidade[u]);
        }
      }
    }
  }
  sum+=11;
  sum=sum+(99*9*3);
  printf("\n\nSUM of all letters is %llu.\n\n",sum);
  return 0;
}
