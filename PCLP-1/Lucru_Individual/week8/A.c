#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int durata_secunde(const char *s, double *out) {
  char *str_end = NULL;
  double val = strtof(s, &str_end);

  if (str_end == s) {
    return 1;
  }

  if (!(val >= 0.0 && val <= 1000000)) {
    return 2;
  }

  double rez = 0.0;
  if (strncmp(str_end, "ms", 2) == 0) {
    rez = val * 0.001;
    str_end += 2;
  } else if (strncmp(str_end, "s", 1) == 0) {
    rez = val;
    str_end += 1;
  } else if (strncmp(str_end, "min", 3) == 0) {
    rez = val * 60;
    str_end += 3;
  } else if (strncmp(str_end, "h", 1) == 0) {
    rez = val * 3600;
    str_end += 1;
  } else {
    return 3;
  }

  while (isspace(*str_end)) {
    str_end++;
  }
  if (*str_end != '\0') {
    return 4;
  }

  *out = rez;

  return 0;
}

int main() {
  char s[100];
  double out;
  scanf("%s", s);
  char *c = s;

  switch (durata_secunde(s, &out)) {
  case 0:
    printf("%s => %g\n", c, out);
    break;
  case 1:
    printf("Eroare: lipsa numarului\n");
    break;
  case 2:
    printf("Eroare: numar in afara intervalului [0, 1000000]\n");
    break;
  case 3:
    printf("Eroare: unitati necunoscute\n");
    break;
  case 4:
    printf("Eroare: caractere suplimentare nepermise\n");
    break;
  }

  return 0;
}