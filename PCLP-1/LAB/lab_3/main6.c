#include <stdio.h>

int is_prime(long int n){
  if(n <= 1){
    return 0;
  }

  if(n <= 3){
    return 1;
  }

  if(n % 2 == 0 || n % 3 == 0){
    return 0;
  }

  for(long int d = 5; d * d <= n; d += 6){
    if(n % d == 0 || n % (d + 2) == 0){
      return 0;
    }
  }

  return 1;
}

int main(){
  long int n;
  scanf("%ld", &n);

  int ok = is_prime(n);
  printf("%d\n", ok);

  return 0;
}