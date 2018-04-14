#include <stdio.h>
#include <stdbool.h>
bool chkprime(long n){
	if (n <= 1) {
		return false;
	}
	else if (n <= 3) {
		return true;
	}
	else if (n % 2 == 0 || n % 3 == 0) {
		return false;
	}
	else {
		long i = 5;
		while (i * i <= n) {
			if (n % i == 0 || n % (i + 2) == 0) {
				return false;
			}
			else {
				i = i + 6;
			}
		}
		return true;
	}
}
void main(void){
    long sum=0;
    for(int i=2;i<2000000;i++){
      if(chkprime(i)){
        sum+=i;
      }
    }
    printf("\nSUM = %li\n\n",sum);
}
