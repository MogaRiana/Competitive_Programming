#include <stdio.h>

void swap_ptr(int **p, int **q){
  int *aux = *p;
  *p = *q;
  *q = aux;
}

int main(){
  int *p = (int *)0x123;
  int *q = (int *)0x456;

  printf("p = %p, q = %p\n", p, q);
  swap_ptr(&p, &q);
  printf("p = %p, q = %p\n", p, q);

  return 0;
}