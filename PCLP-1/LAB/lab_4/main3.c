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

void sort_array(int n, int v[]){
  for(int i = 0; i < n - 1; i++){
    int min = i;
    for(int j = i + 1; j < n; j++){
      if(v[j] < v[min]){
        min = j;
      }
    }

    if(min != i){
      int tmp = v[i];
      v[i] = v[min];
      v[min] = tmp;
    }
  }
}

int main(){
  int v[N];
  int n = read_array(v);

  sort_array(n, v);

  print_array(n, v);

  return 0;
}