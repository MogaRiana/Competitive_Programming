#include <stdio.h>

int power_log(int a, int b){
  if(b == 0){
    return 1;
  }
  if(b == 1){
    return a;
  }

  if(b % 2 == 0){
    int r = power_log(a, b / 2);
    return r * r;
  }
  return power_log(a, b - 1) * a;
}

int main(){
  int p = power_log(7, 3);
  printf("%d\n", p);

  return 0;
}