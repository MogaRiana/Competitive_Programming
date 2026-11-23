#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrom(char *str) {
  int i = 0, j = strlen(str) - 2;
  while (i < j) {
    if (str[i] == ' ') {
      i++;
      continue;
    }
    if (str[j] == ' ') {
      j--;
      continue;
    }
    if (tolower(str[i]) != tolower(str[j])) {
      return 0;
    }

    i++;
    j--;
  }

  return 1;
}

int main() {
  char *str = malloc(1000 * sizeof(char));
  if (str == NULL) {
    return -1;
  }
  fgets(str, 1000, stdin);

  if (is_palindrom(str)) {
    printf("PALINDROME");
  } else {
    printf("NOT PALINDROME");
  }

  free(str);

  return 0;
}