#include <stdio.h>
#include <math.h>
int chkprime(int x){
  int count=0,i=0;
  for(i=2;i<=(x/2);i++){
    if(x%i==0){
      count++;
    }
  }
  if(count==0)
    return 1;
  else
    return 0;
}
void main(void){
  unsigned long bigjohn;
  int i=0,div=0;
  scanf("%lu",&bigjohn);
    for(i=2;i<bigjohn;i++){
      if(bigjohn%i==0){
        if(chkprime(i)==1){
          div=i;
        }
      }
    }
  printf("\nMaior Divisor Primo: %i \n\n",div);
}
