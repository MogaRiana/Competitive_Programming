#include <stdio.h>

#define NMAX 100

void multiply_matrix(int n, int m, int p, int a[NMAX][NMAX],
    int b[NMAX][NMAX], int c[NMAX][NMAX]){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < p; j++){
      for(int k = 0; k < m; k++){
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}

void power_matrix(int n, int a[NMAX][NMAX], int k, int b[NMAX][NMAX]){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == j) {
        b[i][j] = 1;
      } else {
        b[i][j] = 0;
      }
    }
  }

  int tmp[NMAX][NMAX];
  
  for(int i = 0; i < k; i++){

    multiply_matrix(n, n ,n, a, b, tmp);
    
    for(int r = 0; r < n; r++){
      for(int c = 0; c < n; c++){
        b[r][c] = tmp[r][c];
        tmp[r][c] = 0;
      }
    }
  }
}

int main(){
  int n = 4;
  int a[NMAX][NMAX] = {
      { 0,  1,  1,  1},
      { 1,  1,  1,  1},
      { 0, 10,  0,  0},
      { 0, 10,  0,  0}
  };

  int k;
  int b[NMAX][NMAX];
  scanf("%d", &k);
  power_matrix(n, a, k, b);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      printf("%d ", b[i][j]);
    }
    printf("\n");
  }

  return 0;
}