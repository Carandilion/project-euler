#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// SEPA: A Simple, Efficient Permutation Algorithm - http://www.quickperm.org/soda_submit.php
void swap(char *s, int a, int b)
{
   char temp=s[a];
   s[a] = s[b];
   s[b] = temp;
}
int permute(char *str, int len){
  int key=len-1;
  int newkey=len-1;
  while( (key > 0) && (str[key] <= str[key-1]) ){
    key--;
  }
  key--;
  if( key < 0 )
    return 0;
  newkey=len-1;
  while( (newkey > key) && (str[newkey] <= str[key]) ){
    newkey--;
  }
  swap(str, key, newkey);
  len--;
  key++;
  while(len>key){
    swap(str,len,key);
    key++;
    len--;
  }
  return 1;
}
// SEPA: A Simple, Efficient Permutation Algorithm - http://www.quickperm.org/soda_submit.php
int main(void){
  unsigned count=0;
  char str[] = {"0123456789"};
  do{
   count++;
   // printf("\n%s\n\n",str);
   if (count == 1000000)
    break;
  }while ( permute(str,strlen(str)) );
  printf("\nAnswer is %s.\n\n",str);
  return 0;
}
