#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace_all(const char *s, const char *vechi, const char *nou) {
  int sizes = strlen(s);
  int sizevechi = strlen(vechi);
  int sizenou = strlen(nou);

  int nrap = 0;
  const char *temp = s;
  temp = strstr(temp, vechi);
  while (temp != NULL) {
    nrap++;
    temp += sizevechi;
    temp = strstr(temp, vechi);
  }

  int sizerez = sizes + nrap * (sizenou - sizevechi);
  char *rez = malloc(sizerez + 1);
  if (rez == NULL) {
    free(rez);
    exit(1);
  }

  char *dest = rez;
  const char *cs = s;
  const char *temp2 = strstr(cs, vechi);
  while (temp2 != NULL) {
    int len = temp2 - cs;

    memcpy(dest, cs, len);
    dest += len;

    memcpy(dest, nou, sizenou);
    dest += sizenou;

    cs = temp2 + sizevechi;
    temp2 = strstr(cs, vechi);
  }

  strcpy(dest, cs);

  return rez;
}

int main() {
  char s[100], vechi[100], nou[100];
  scanf("%s%s%s", s, vechi, nou);

  char *rez = replace_all(s, vechi, nou);
  printf("%s\n", rez);
  free(rez);

  return 0;
}