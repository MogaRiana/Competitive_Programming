#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char BUFFER[1000];

char **read_vec(int N) {
  char **v = malloc(N * sizeof(char *));
  if (v == NULL) {
    exit(1);
  }

  for (int i = 0; i < N; i++) {
    scanf("%s", BUFFER);
    v[i] = malloc(strlen(BUFFER) + 1);
    if (v[i] == NULL) {
      for (int j = 0; j < i; j++) {
        free(v[j]);
      }
      free(v);
      exit(1);
    }
    strcpy(v[i], BUFFER);
  }
  return v;
}

void free_vec(int n, char **v) {
  for (int i = 0; i < n; i++) {
    free(v[i]);
  }

  free(v);
}

void print_vec(int n, char **v) {
  for (int i = 0; i < n; i++) {
    printf("0%s0", v[i]);
  }
  printf("\n");
}

void sort_strings(int n, char **v) {}

int main() {
  int n;
  scanf("%d", &n);
  getchar();
  char **v = read_vec(n);
  print_vec(n, v);

  free_vec(n, v);

  return 0;
}