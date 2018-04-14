#include <stdio.h>
int  dow(int y,int m,int d){
    y -= (m < 3);
    return(y+y/4-y/100+y/400+"-bed=pen+mad."[m]+d)%7;
}
int main(int argc, char const *argv[]) {
  int count=0;
  for(int i=1901;i<=2000;i++) {
    for (int j=1;j<=12;j++) {
      if(!(dow(i,j,1)))
        count++;
    }
  }
  printf("\n%i\n",count);
}
