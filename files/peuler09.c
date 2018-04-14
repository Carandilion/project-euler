#include <stdio.h>
#include <math.h>
void main(void){
  int a=0,b=0,c=0,i=0,j=0,z=0;
  for(i=1;i<1000;i++){
    for(j=1;j<1000;j++){
      for(z=1;z<1000;z++){
        a=i;
        b=j;
        c=z;
        if(a+b+c==1000 && (pow(a,2)+pow(b,2)==pow(c,2))){
          printf("\nA[%i]+B[%i]+C[%i]=1000 e Produto =%i\n\n",a,b,c,a*b*c);
        }
      }
    }
  }
}
