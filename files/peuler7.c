#include <stdio.h>

int chkprime(int x){                                       // VERIFICA SE O NÚMERO É UM NÚMERO PRIMO
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
  int i=2,index=1;
  do{
    if(chkprime(i)){
      printf("\n[%i]:: %i\n ",index,i);
      index++;
    }
  i++;
  }while(index!=10002);                                    // ACHA UM PRIMO DE INDEX N-1 IE 10001
}
