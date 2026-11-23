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

  printf("A * B = \n");

  for(int i = 0; i < n; i++){
    for(int j = 0; j < p; j++){
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }
}

int main(){
  int a[NMAX][NMAX] = {
    { 0,  1,  1,  1},
    { 1,  1,  1,  1},
    { 0, 10,  0,  0},
    { 0, 10,  0,  0}
  };

  int b[NMAX][NMAX] = {
    { -1, 10,  1},
    { -2, 20,  2},
    { -3, 30,  3},
    { -4, 40,  4}
  };

  int c[NMAX][NMAX];

  multiply_matrix(4, 4, 3, a, b, c);

  return 0;
}