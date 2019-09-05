//The reason the code breaks when n is large is because the int type is represented by 4 bytes.
//The maximum integer that can be represented by int is 2^31 - 1 = 2147483647.
//If our sum is above this number, we will get a wrong result.
//Note you use the following statement to show the size of int
//printf("The size of int is %ld\n", sizeof(int));

/*
  Compute the sum of the integers
  from 1 to n, for a given n    
*/
#include <stdio.h>
#include "./utils.h"

int sum(int n) {
  int i, sum;
	sum = 0;
	i = 1;
	while (i <= n) {
		sum = sum + i;
		i = i + 1;
	}
  return sum;
}

int main() {
  int numbs[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
  int n;
  printf("Among 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000\n");
  for(int i = 0; i < length(numbs); i++) { 
    n = numbs[i];
    // Base case
    if(i == 0) { continue; }
    // Div(5) ? break : continue
    if(sum(numbs[i]) % 5 != 0) { break; }
  }
  printf("The smallest number to break the code is %d\n", n);
	return 0;
}

