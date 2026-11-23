#include <stdio.h>

void swap_int(int *p, int *q){
  int aux = *p;
  *p = *q;
  *q = aux;
}

int main(){
  int  p = 3, q = 9;
  printf("p = %d, q = %d\n", p, q);
  swap_int(&p, &q);
  printf("p = %d, q = %d\n", p, q);

  return 0;
}