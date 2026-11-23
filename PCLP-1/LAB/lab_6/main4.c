#include <stdio.h>
#include <stdlib.h>

int **alloc_mattrix(int n, int *m) {
  int **a = malloc(n * sizeof(int *));
  if (a == NULL) {
    free(a);
    printf("Alocarea a esuat\n");
    return NULL;
  }

  for (int i = 0; i < n; i++) {
    a[i] = malloc(m[i] * sizeof(int));
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

void read_matrix(int n, int *m, int **v) {
  int k = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m[i]; j++) {
      v[i][j] = k++;
    }
  }
}

void print_matrix(int n, int *m, int **v) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m[i]; j++) {
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
  int n;
  scanf("%d", &n);

  int *m = malloc(n * sizeof(int));
  if (m == NULL) {
    printf("Alocarea a esuat\n");
    free(m);
    return 1;
  }

  for (int i = 0; i < n; i++) {
    scanf("%d", &m[i]);
  }

  int **a = alloc_mattrix(n, m);
  read_matrix(n, m, a);
  print_matrix(n, m, a);
  free_matrix(n, a);
  free(m);

  return 0;
}