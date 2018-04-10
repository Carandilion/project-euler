#include <stdio.h>
#define size 1000
int main(){
  int sum=0;
  for(int i=0;i<size;i++){
    if(i%3==0 || i%5==0)
      sum=sum+i;
  }
  printf("\n%i\n\n",sum);
}
