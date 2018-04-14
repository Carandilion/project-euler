#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Divof{
  int id;
  long long unsigned sumd;
  char divisores[300];
}number[10001];
void divisor(long long unsigned x,FILE *divsaved){
  long long unsigned i;
  int count=0;
  for(i=1;i*i<x;i++){
    if(x % i == 0 && i!=1){
      fprintf(divsaved,"%llu,",i);
      fprintf(divsaved,"%llu,",x/i);
      count++;
    }
  }
  if(!count)
    fprintf(divsaved,"0");
  fprintf(divsaved,"\n");
}
int main(int argc, char const *argv[]) {
  FILE *divsaved;
  divsaved = fopen("peuler21.txt","r");
  char *ptr;
  char crntfinal[6];
  char crnt,next;
  int  aux=0,pos=0;
  unsigned long long sumamicable=0;
  for(int i = 0; i <= 10000; i++){
    number[i].id=i;
    fgets(number[i].divisores,300,divsaved);
    number[i].sumd=0;
    crnt='0';
    pos=0;
    crntfinal[1]=' ';
    crntfinal[2]=' ';
    crntfinal[3]=' ';
    crntfinal[4]=' ';
    crntfinal[5]=' ';
    for(int j=0 ; j <= 300 ; j++){
      crnt = number[i].divisores[j];
      next = number[i].divisores[j+1];
      if(crnt == '\0'){
        break;
      }
      else if(crnt == ','){
        continue;
      }
      else if(next == ',' ){
        crntfinal[pos]=crnt;
        number[i].sumd+=strtol(crntfinal,&ptr,10);
        pos=0;
        crntfinal[1]=' ';
        crntfinal[2]=' ';
        crntfinal[3]=' ';
        crntfinal[4]=' ';
        crntfinal[5]=' ';
      }
      else{
        crntfinal[pos]=crnt;
        pos++;
      }
    }
    number[i].sumd++;
  }
  for(int i=200; i<=10000; i++){
    for(int j=200 ;j<=10000; j++){
      if(number[i].sumd == number[j].id && number[j].sumd == number[i].id && i!=j ){
        printf("\nPair(%i,%i)\n",number[i].id,number[j].id);
        sumamicable+=(number[i].id+number[j].id);
        i=number[j].id;
        break;
      }
    }
  }
  printf("\nSoma dos Amicables: %llu.\n",sumamicable);
  return 0;
}
