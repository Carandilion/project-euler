#include <stdio.h>
void main(){
  int div[20],i=0,count=0;
  for(i=0;i<20;i++)
    div[i]=i+1;
  i=20;
  do{
    for(int pos=18;pos>2;pos--){
        if(i%div[pos]==0){
          count++;
        }
        else{
          break;
        }
    }
    if(count==16){
      printf("\n%i\n\n",i);
      break;
    }
    i+=20;
    count=0;
  }while(count!=16);
}
