#include <stdio.h>
int paln(int n){
  int reverso=0,origem=n,resto;
  // printf("\nORIGINAL = %i\n\n",n);
  while( n!=0 ){
    resto = n%10;
    // printf("\nRESTO = %i\n\n",resto);
    reverso = reverso*10 + resto;
    // printf("REVERSO = %i\n\n",reverso);
    n=n/10;
    // printf("N = %i\n\n",n);
    // printf("\n\n");
  }
  // printf("\n\nREVERSO FINAL = %i\n\n",reverso);
  if(origem==reverso)
    return 1;
  else
    return 0;
}
void main(void){
  int maior=0;
  for(int x=100;x<999;x++){
    for(int y=100;y<999;y++){
      if(paln(x*y)==1){
        if(x*y>maior){
          maior=x*y;
        }
      }
    }
  }
  printf("\n%i\n\n",maior);
}
