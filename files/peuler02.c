#include <stdio.h>
#define size 9999
int main(){
  int sum=0,i=0,x[size];
  x[0]=1;
  x[1]=1;
  for(i=2;i<size;i++){
    x[i]=x[i-1]+x[i-2];
    if(x[i]%2==0)
      sum=sum+x[i];
    if(x[i]>4000000){
      break;
    }
  }
  printf("\n%i\n\n",sum);
}
