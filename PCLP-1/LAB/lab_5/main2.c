#include <stdio.h>

void f(int *n, int *v){
  scanf("%d", n);

  for(int i = 0; i < *n; i++){
    scanf("%d", &v[i]);
  }
}

int main(){
  int n;
  int v[100];

  f(&n, v);
  printf("n = %d\n", n);
  for(int i = 0; i < n; i++){
    printf("%d ", v[i]);
  }

  return 0;
}