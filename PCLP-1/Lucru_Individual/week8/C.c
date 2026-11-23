#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f(const char *s) {
  char *c = strdup(s);

  char *studenti[1000];
  int n = 0;
  char *stud = strtok(c, ";");

  while (stud != NULL) {
    studenti[n] = stud;
    n++;
    stud = strtok(NULL, ";");
  }

  for (int i = 0; i < n; i++) {
    char *nume = strtok(studenti[i], ":");
    char *nota = strtok(NULL, ",");
    float nr = 0, med = 0;

    while (nota != NULL) {
      nr++;
      med = med + atoi(nota);
      nota = strtok(NULL, ",");
    }

    printf("%s: %.2f\n", nume, med / nr);
  }

  free(c);
}

int main() {
  char s[1000];
  scanf("%s", s);
  f(s);

  return 0;
}