
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
  // fprintf(divsaved,"%llu,1,",x);
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
  // for (int i = 0; i <= 10000; i++) {
  //   divisor(i,divsaved);
  // }

  for(int i = 0; i <= 10000; i++){                         //GAMBIARRA!
    number[i].id=i;
    fgets(number[i].divisores,300,divsaved);
    // INICIALIZANDO
    number[i].sumd=0;
    crnt='0';
    pos=0;
    crntfinal[1]=' ';
    crntfinal[2]=' ';
    crntfinal[3]=' ';
    crntfinal[4]=' ';
    crntfinal[5]=' ';
    //
    // printf("\nNEW ITERATION\n");
    for(int j=0 ; j <= 300 ; j++){

      // printf("\n%s\n",number[i].divisores);
      crnt = number[i].divisores[j];
      next = number[i].divisores[j+1];
      // printf("\n%c and %c\n",crnt,next);

      if(crnt == '\0'){
        // printf("\nFOUND EOL\n");
        break;
      }

      else if(crnt == ','){
        continue;
      }

      else if(next == ',' ){
        crntfinal[pos]=crnt;
        number[i].sumd+=strtol(crntfinal,&ptr,10);
        // printf("\nadd %lu += %llu \n",strtol(crntfinal,&ptr,10),number[i].sumd);
        pos=0;
        crntfinal[1]=' ';
        crntfinal[2]=' ';
        crntfinal[3]=' ';
        crntfinal[4]=' ';
        crntfinal[5]=' ';
      }

      else{
        // printf("\niterating\n");
        // printf("\naddin %c to %s\n",crnt,crntfinal);
        crntfinal[pos]=crnt;
        // printf("\nresult: %s.\n",crntfinal);
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
