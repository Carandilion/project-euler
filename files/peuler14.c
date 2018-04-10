#include "stdio.h"
#define size 1000000

int collatzsize(unsigned long long x){        //A MAIOR ITERAÇÃO SEMPRE VAI SER DE UM NÚMERO IMPAR
  int count=0;                                //ENTÃO EU VOU RETIRAR A VERIFICAÇÃO DE PARES.
  if(x%2==0){
    return 0;
  }
  while (x!=1) {
    if (x%2==0) {
      x/=2;
      count++;
    }
    else{
      x=(3*x)+1;
      count++;
    }
  }
  return count;
}

int main(int argc, char const *argv[]) {
  // printf("%i\n",collatzsize(97));
  int biggest=0,index=0,temp;
  for (int i = size; i > size/2; i--) {
    temp=collatzsize(i);
    if(temp>=biggest){
     biggest=temp;
     index=i;
   }
  }
  printf("\n\nBiggest Chain less than %i is %i at %i.\n\n",size,biggest,index);
  return 0;
}
