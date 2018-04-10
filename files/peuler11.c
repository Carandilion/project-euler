#include <stdio.h>
void main(void){
  unsigned long max=0;
  FILE *numberfile;
  numberfile = fopen("peuler11.txt","r");
  int x[20][20];
  for(int i=0;i<20;i++){
    for(int j=0;j<20;j++){
      fscanf(numberfile,"%d",&x[i][j]);
    }
  }
  for(int i=0;i<20;i++){
    printf("\n");
    for(int j=0;j<20;j++){
      if(x[i][j]<10)
      printf("[0%i] ",x[i][j]);
      else
      printf("[%i] ",x[i][j]);
    }
  }

  for(int i=0;i<20;i++){
    for(int j=0;j<20;j++){
      if(x[i][j]*x[i][j+1]*x[i][j+2]*x[i][j+3] > max && (i+3 < 20) && (j+3 < 20)) {
        max=(x[i][j]*x[i][j+1]*x[i][j+2]*x[i][j+3]);
      }
    }
  }
  for(int i=0;i<20;i++){
    for(int j=0;j<20;j++){
      if(x[i][j]*x[i+1][j]*x[i+2][j]*x[i+3][j] > max && (i+3 < 20) && (j+3 < 20)) {
        max=x[i][j]*x[i+1][j]*x[i+2][j]*x[i+3][j];
      }
    }
  }
  for(int i=0;i<20;i++){
    for(int j=0;j<20;j++){
      if(x[i][j]*x[i+1][j+1]*x[i+2][j+2]*x[i+3][j+3] > max && (i+3 < 20) && (j+3 < 20)){
        max=x[i][j]*x[i+1][j+1]*x[i+2][j+2]*x[i+3][j+3];
      }
    }
  }
  for(int i=0;i<20;i++){
    for(int j=0;j<20;j++){
      if(x[i][j]*x[i+1][j-1]*x[i+2][j-2]*x[i+3][j-3] > max && (i+3 < 20) && (j-3 > -1)){
        max=x[i][j]*x[i+1][j-1]*x[i+2][j-2]*x[i+3][j-3];
      }
    }
  }
  printf("\n\nPRODUCT: %lu\n\n",max);
}
