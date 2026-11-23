#include <stdio.h>
#include <stdlib.h>

int insert_slice(int *v, size_t *n, size_t *capacity, size_t position,
                 size_t first, size_t count) {
  if (position > *n || first + count > *n) {
    return 0;
  }
  if (count == 0) {
    return 1;
  }

  size_t needed = *n + count;
  if (needed > *capacity) {
    *capacity = needed;

    int *tmp = realloc(v, *capacity * sizeof(int));
    if (tmp == NULL) {
      return 0;
    }

    v = tmp;
  }

  for (int i = *n - 1; i >= position; i--) {
    v[i + count] = v[i];
  }
  for (int i = count - 1; i >= 0; i--) {
    v[position + i] = v[first + i];
  }

  *n += count;

  return 1;
}

int main() {
  size_t capacity = 100, n;
  scanf("%lu", &n);

  int *v = malloc(capacity * sizeof(int));
  if (v == NULL) {
    printf("[EROARE] nu s-a alocat memorie!");
    free(v);
    return 1;
  }

  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }

  printf("Initial: [");
  for (int i = 0; i < n; i++) {
    printf("%d%s ", v[i], (i == n - 1) ? "]\n" : ", ");
  }

  int position, first, count;
  printf("position: \n first: \n count: \n");
  scanf("%d%d%d", &position, &first, &count);

  if (insert_slice(v, &n, &capacity, position, first, count)) {
    printf("Rezultat: [");
    for (int i = 0; i < n; i++) {
      printf("%d%s ", v[i], (i == n - 1) ? "]\n" : ", ");
    }
  } else {
    printf("[EROARE] nu s-au inserat elementele!");
  }

  free(v);

  return 0;
}