// printf("\n\n");
// aux=triangle[0][0];
// for (i = 0; i < 15; i++){
//
//   printf("\n%i at row %i.\n",aux,auxrow);
//   bestp=0;
//   sum+=aux;
//   aux=0;
//
//   }
//
//   for (j = 0; j < 2; j++){
//     if(triangle[i+1][row+j] > aux && row+j>=0){
//       aux=triangle[i+1][row+j];
//       auxrow=row+j;
//     }
//   }
// }
// return cmp ( t[x+1][y] , t[x+1][y+1] ) + cmp ( bp( 15, 15, t , x+1 , y) , bp( 15, 15, t , x+1 , y+1) ) ;
// return cmp (bp( 15, 15, t , x+2 , y) + t[x+1][y] , bp( 15, 15, t , x+2 , y+1) + t[x+1][y] ) + t[x+1][y] ;

#include <stdio.h>
#define indexx 0
#define indexy 0

int cmp(int a,int b){
  if(a==b){
    return 0;
  }
  else if(a > b){
    return a;
  }
  else{
    return b;
  }
}

int bp( int i ,int j ,int t[i][j] , int x , int y ){

  if( x + 1 > i || y + 1 > j )                                    // LIMITADOR TRIÂNGULO
    return 0;
  else if (x == i)
    return t[x][y];
  else
    return t[x][y]+cmp(bp(15,15,t,x+1,y),bp(15,15,t,x+1,y+1));
}
int main(int argc, char const *argv[]){

  int t[15][15]=

    {
    75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    95,64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    17,47,82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    18,35,87,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    20, 4,82,47,65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    19, 1,23,75, 3,34, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    88, 2,77,73, 7,63,67, 0, 0, 0, 0, 0, 0, 0, 0,
    99,65, 4,28, 6,16,70,92, 0, 0, 0, 0, 0, 0, 0,
    41,41,26,56,83,40,80,70,33, 0, 0, 0, 0, 0, 0,
    41,48,72,33,47,32,37,16,94,29, 0, 0, 0, 0, 0,
    53,71,44,65,25,43,91,52,97,51,14, 0, 0, 0, 0,
    70,11,33,28,77,73,17,78,39,68,17,57, 0, 0, 0,
    91,71,52,38,17,14,91,43,58,50,27,29,48, 0, 0,
    63,66, 4,68,89,53,67,30,73,16,69,87,40,31, 0,
     4,62,98,27,23, 9,70,98,73,93,38,53,60, 4,23}
    ;


  for (size_t i=0; i<15; i++){
    printf("\n");
    for (size_t j=0; j<15 ; j++){
      if(t[i][j]!=0){
        if(t[i][j]<10)
          printf("[0%i] ",t[i][j]);
        else
          printf("[%i] ",t[i][j]);
      }
    }
  }
  printf("\n\nBEST path of start [%i] is %i\n\n",t[indexx][indexy],bp(15,15,t,indexx,indexy));
  return 0;

}
