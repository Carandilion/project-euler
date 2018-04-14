#include <stdio.h>
int ndiv(unsigned long long x){
  int count=0,i;
  for(i=1;i*i<=x;i++){
    if(x % i == 0)
      count+=2;
    if(i*i == x )
      count-=1;
  }
  return count;
}
void main(void){
  long ntriangle=0;
  int i;
  for(i=1;i!=0;i++){
    ntriangle=(i*(i+1))/2;
    if(ndiv(ntriangle)>=500){
      printf("\n\nFound at index=%i. Value of %li. %i divisors.\n\n",i,ntriangle,ndiv(ntriangle));
      break;
    }
  }
}
