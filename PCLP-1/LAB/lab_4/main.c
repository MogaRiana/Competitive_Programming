#include <stdio.h>

#define N 100

int read_array(int v[]){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%d", &v[i]);
  }

  return n;
}

void print_array(int n, int v[]){
  for(int i = 0; i < n; i++){
      printf("%d ", v[i]);
  }
  printf("\n");
}

int main(){
  int v[N];
  int n = read_array(v);

  print_array(n, v);

  return 0;
}