#include <stdio.h>
#include <stdlib.h>

int **alloc_mattrix(int n, int m) {
  int **a = malloc(n * sizeof(int));
  if (a == NULL) {
    free(a);
    printf("Alocarea a esuat\n");
    return NULL;
  }

  for (int i = 0; i < n; i++) {
    a[i] = malloc(m * sizeof(int));
    if (a[i] == NULL) {
      for (int j = 0; j < i; j++) {
        free(a[j]);
      }
      free(a);
      printf("Alocarea a esuat\n");
      return NULL;
    }
  }

  return a;
}

void read_matrix(int n, int m, int **v) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &v[i][j]);
    }
  }
}

void print_matrix(int n, int m, int **v) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", v[i][j]);
    }
    printf("\n");
  }
}

void free_matrix(int n, int **a) {
  for (int i = 0; i < n; i++) {
    free(a[i]);
  }
  free(a);
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  int **a = alloc_mattrix(n, m);
  read_matrix(n, m, a);
  print_matrix(n, m, a);
  free_matrix(n, a);

  return 0;
}