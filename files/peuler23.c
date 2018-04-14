#include <stdio.h>
#include <math.h>
typedef unsigned int ui;
ui sumdivisors(ui x){
  ui sum=0;
  for(ui i=2; i*i<=x;i++){
    if(x % i == 0){
      sum+=i;
      sum+=x/i;
    }
    if(i*i==x){
      sum-= i;
    }
  }
  return sum+1;
}
int isab(ui x){
  if(sumdivisors(x) > x )
    return 1;
  else
    return 0;
}
int main(int argc, char const *argv[]) {
  ui sum=0;
  ui abundants[20162]={0};
  ui sumabundants[20162]={0};
  ui temp;
  int true=1;
  for(ui i=1;i<20161;i++){
    if(isab(i)){
      abundants[i]=i;
    }
  }
  for (ui i = 1; i <=20161; i++) {
    if(abundants[i]==0){
      continue;
    }
    for (ui j = 1;j<=20161;j++) {
      if(abundants[j]==0){
        continue;
      }
      temp=abundants[i]+abundants[j];
      if(temp>20161){
        break;
      }
      sumabundants[temp]=1;
    }
  }
  for (ui i = 1; i <= 20161; i++) {
    if(sumabundants[i]==0)
      sum+=i;
  }
  printf("\n%u\n",sum);
  return 0;
}
