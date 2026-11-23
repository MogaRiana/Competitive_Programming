#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
  char *nume;
  char grupa[5];
  double medie;
} stud;

void srt(stud *s, int n) {
  for (int i = 0; i < n; i++) {
    int m = i;
    for (int j = i + 1; j < n; j++) {
      if (strcmp(s[m].nume, s[j].nume) > 0) {
        m = j;
      }
    }

    stud temp = s[i];
    s[i] = s[m];
    s[m] = temp;
  }
}

void elib_stud(stud *s, int n) {
  for (int i = 0; i < n; i++) {
    free(s[i].nume);
  }

  free(s);
}

stud *read_stud(int n) {
  stud *s = malloc(n * sizeof(stud));
  if (s == NULL) {
    exit(1);
  }
  for (int i = 0; i < n; i++) {
    char buf[20];
    scanf("%s %s %lf", buf, s[i].grupa, &s[i].medie);

    s[i].nume = malloc((strlen(buf) + 1) * sizeof(char));
    if (s[i].nume == NULL) {
      elib_stud(s, n);
      exit(1);
    }

    strcpy(s[i].nume, buf);
  }

  return s;
}

int main() {
  int n;
  scanf("%d", &n);
  stud *s = read_stud(n);

  srt(s, n);
  for (int i = 0; i < n; i++) {
    printf("%s\t%s\t%.2lf\n", s[i].nume, s[i].grupa, s[i].medie);
  }

  elib_stud(s, n);

  return 0;
}