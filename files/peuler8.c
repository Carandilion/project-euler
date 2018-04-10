#include <stdio.h>
#define size 1000

long long sumnext(int numbers[],int x){
  // printf("\nhere:%i\n\n",numbers[x]);
  long long sum=1;
  int i;
  for(i=x;i<(x+13);i++){
    sum=sum*numbers[i];
  }
  printf("\n%lli\n\n",sum);
  return sum;
}

void main(void){
  int i;
  long long max=0;
  FILE *numberfile;
  numberfile = fopen("peuler8.txt","r");
  int numbers[size];
  for(i=0;i<size;i++)
    fscanf(numberfile, "%1d", &numbers[i]);
  for(i=0;i<size-1;i++){
    if(sumnext(numbers,i) > max){
      max=sumnext(numbers,i);
    }
  }
  printf("\nMAX= %lli\n\n",max);
}
