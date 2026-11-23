#include <stdio.h>
#include <stdlib.h>

int f1(char **addr_p) {
  char *s = malloc(32 * sizeof(char));
  int len = 0, buf = 32;
  char c;

  while (1) {
    c = (char)getchar();
    if (len + 1 >= buf) {
      char *temp = realloc(s, buf * 2);
      if (temp == NULL) {
        free(temp);
        return 0;
      }
      buf *= 2;
      s = temp;
    }

    s[len++] = c;

    if (c == '\n') {
      break;
    }
  }
  s[len] = '\0';

  int voc = 0, cons = 0;
  for (int i = 0; i < len; i++) {
    if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z') {
      char lower = s[i];
      if (s[i] >= 'A' && s[i] <= 'Z') {
        lower = s[i] + ('a' - 'A');
      }

      if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' ||
          lower == 'u') {
        voc++;
      } else {
        cons++;
      }
    }
  }

  for (int i = 0; i < len; i++) {
    if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z') {
      char loweri = s[i];
      if (s[i] >= 'A' && s[i] <= 'Z') {
        loweri = s[i] + ('a' - 'A');
      }

      if (loweri == 'a' || loweri == 'e' || loweri == 'i' || loweri == 'o' ||
          loweri == 'u') {
        int min = i;
        char valmin = loweri;
        for (int j = i + 1; j < len; j++) {
          if (s[j] >= 'A' && s[j] <= 'Z' || s[j] >= 'a' && s[j] <= 'z') {
            char lowerj = s[j];
            if (s[j] >= 'A' && s[j] <= 'Z') {
              lowerj = s[j] + ('a' - 'A');
            }

            if (lowerj == 'a' || lowerj == 'e' || lowerj == 'i' ||
                lowerj == 'o' || lowerj == 'u') {
              if (valmin > lowerj) {
                min = j;
                valmin = lowerj;
              }
            }
          }
        }
        char tmp = s[i];
        s[i] = s[min];
        s[min] = tmp;
      }
    }
  }

  for (int i = 0; i < len; i++) {
    if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z') {
      char loweri = s[i];
      if (s[i] >= 'A' && s[i] <= 'Z') {
        loweri = s[i] + ('a' - 'A');
      }

      if (!(loweri == 'a' || loweri == 'e' || loweri == 'i' || loweri == 'o' ||
            loweri == 'u')) {
        int min = i;
        char valmin = loweri;
        for (int j = i + 1; j < len; j++) {
          if (s[j] >= 'A' && s[j] <= 'Z' || s[j] >= 'a' && s[j] <= 'z') {
            char lowerj = s[j];
            if (s[j] >= 'A' && s[j] <= 'Z') {
              lowerj = s[j] + ('a' - 'A');
            }

            if (!(lowerj == 'a' || lowerj == 'e' || lowerj == 'i' ||
                  lowerj == 'o' || lowerj == 'u')) {
              if (valmin > lowerj) {
                min = j;
                valmin = lowerj;
              }
            }
          }
        }
        char tmp = s[i];
        s[i] = s[min];
        s[min] = tmp;
      }
    }
  }

  *addr_p = s;
  return (voc > cons) ? voc - cons : cons - voc;
}

int main() {
  char *p;
  int k = f1(&p);

  printf("%d\n", k);
  printf("%s", p);

  free(p);

  return 0;
}