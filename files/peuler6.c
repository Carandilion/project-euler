#include <stdio.h>
#include <math.h>

int sumpow(int x){
  if(x==1)
    return 1;
  else
    return x+sumpow(x-1);
}

double powsum(double x){
  if(x==1)
    return 1;
  else
    return pow(x,2)+powsum(x-1);
}
void main(void){
  printf("\n%f\n\n",pow(sumpow(100),2)-powsum(100));
}
