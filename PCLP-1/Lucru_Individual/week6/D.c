#include <stdio.h>
#include <stdlib.h>

int *sum(int *v1, int N1, int *v2, int N2, int *N3) {
  int *s = malloc((((N1 > N2) ? N1 : N2) + 1) * sizeof(int));
  if (s == NULL) {
    printf("[EROARE] nu s-a alocat memorie!");
    free(s);
    exit(1);
  }

  int i = N1 - 1, j = N2 - 1;
  int c = 0;
  *N3 = 0;

  while (i >= 0 || j >= 0 || c > 0) {
    int sum = c;

    if (i >= 0) {
      sum += v1[i];
      i--;
    }
    if (j >= 0) {
      sum += v2[j];
      j--;
    }

    s[(*N3)++] = sum % 10;
    c = sum / 10;
  }

  for (int l = 0, r = *N3 - 1; l <= r; l++, r--) {
    int tmp = s[l];
    s[l] = s[r];
    s[r] = tmp;
  }

  return s;
}

int main() {
  int N1, N2;
  scanf("%d%d", &N1, &N2);

  int *v1 = malloc(N1 * sizeof(int));
  int *v2 = malloc(N2 * sizeof(int));

  if (v1 == NULL || v2 == NULL) {
    printf("[EROARE] nu s-a alocat memorie!");
    free(v1);
    free(v2);
    return 1;
  }

  for (int i = 0; i < N1; i++) {
    scanf("%d", &v1[i]);
  }
  for (int i = 0; i < N2; i++) {
    scanf("%d", &v2[i]);
  }

  int N3;
  int *res = sum(v1, N1, v2, N2, &N3);
  for (int i = 0; i < N3; i++) {
    printf("%d", res[i]);
  }

  free(v1);
  free(v2);

  return 0;
}