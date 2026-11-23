#include <stdio.h>
#include <stdlib.h>

int ***alloc_mat3D(int N, int M, int K) {
  int ***mat = malloc(N * sizeof(int **));
  if (mat == NULL) {
    printf("Alocarea a esuat\n");
    free(mat);
    return NULL;
  }
  for (int i = 0; i < N; i++) {
    mat[i] = malloc(M * sizeof(int *));
    if (mat[i] == NULL) {
      for (int ii = 0; ii < i; ii++) {
        free(mat[ii]);
      }
      printf("Alocarea a esuat\n");
      free(mat);
      return NULL;
    }
    for (int j = 0; j < M; j++) {
      mat[i][j] = malloc(K * sizeof(int));
      if (mat[i][j] == NULL) {
        for (int ii = 0; ii < i; ii++) {
          for (int jj = 0; jj < j; jj++) {
            free(mat[i][j]);
          }
          free(mat[i]);
        }
        printf("Alocarea a esuat\n");
        free(mat);
        return NULL;
      }
    }
  }

  return mat;
}

int main() {
  int N, M, K;
  scanf("%d%d%d", &N, &M, &K);

  int ***mat = alloc_mat3D(N, M, K);

  return 0;
}