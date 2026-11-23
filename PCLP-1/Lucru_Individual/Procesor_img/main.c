#include "bmp_io_rgb.h"
#include <string.h>

typedef struct {
  int i;
  int j;
} coord;

void free_img(unsigned char ***img, int N, int M) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      free(img[i][j]);
    }
    free(img[i]);
  }
  free(img);
}

unsigned char ***alloc_img(int N, int M) {
  unsigned char ***img = malloc(N * sizeof(unsigned char **));
  if (!img) {
    free(img);
    return NULL;
  }
  for (int i = 0; i < N; i++) {
    img[i] = malloc(M * sizeof(unsigned char *));
    if (!img[i]) {
      for (int ii = 0; ii < i; ii++) {
        free(img[ii]);
      }
      free(img);
      return NULL;
    }
    for (int j = 0; j < M; j++) {
      img[i][j] = malloc(3 * sizeof(unsigned char));
      if (!img[i][j]) {
        for (int ii = 0; ii < i; ii++) {
          for (int jj = 0; jj < j; jj++) {
            free(img[i][j]);
          }
          free(img[i]);
        }
        free(img);
        return NULL;
      }
    }
  }

  return img;
}

unsigned char ***task3(unsigned char ***img, coord lt, coord rt, coord lb,
                       coord rb, int k, int N, int M) {
  unsigned char ***img3 = alloc_img(N, M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      for (int kk = 0; kk < 3; kk++) {
        img3[i][j][kk] = img[i][j][kk];
      }
    }
  }

  for (int i = (lt.j - k / 2); i <= rt.j + k / 2 - 1; i++) {
    for (int j = lt.i - k / 2; j < lt.i + k / 2; j++) {
      if (j >= 0 && j < N && i >= 0 && i < M) {
        img3[j][i][0] = 255;
        img3[j][i][1] = 0;
        img3[j][i][2] = 0;
      }
    }

    for (int j = lb.i - k / 2; j < lb.i + k / 2; j++) {
      if (j >= 0 && j < N && i >= 0 && i < M) {
        img3[j][i][0] = 255;
        img3[j][i][1] = 0;
        img3[j][i][2] = 0;
      }
    }
  }
  for (int i = lt.i - k / 2; i <= lb.i + k / 2 - 1; i++) {
    for (int j = lt.j - k / 2; j < lt.j + k / 2; j++) {
      if (i >= 0 && i < N && j >= 0 && j < M) {
        img3[i][j][0] = 255;
        img3[i][j][1] = 0;
        img3[i][j][2] = 0;
      }
    }

    for (int j = rt.j - k / 2; j < rt.j + k / 2; j++) {
      if (i >= 0 && i < N && j >= 0 && j < M) {
        img3[i][j][0] = 255;
        img3[i][j][1] = 0;
        img3[i][j][2] = 0;
      }
    }
  }

  return img3;
}

unsigned char ***task4(unsigned char ***img, coord lt, coord rb, int *N,
                       int *M) {
  int newN = rb.i - lt.i + 1;
  int newM = rb.j - lt.j + 1;

  if (newN < 0 || newM < 0) {
    return NULL;
  }

  unsigned char ***img4 = alloc_img(newN, newM);
  for (int i = 0; i < newN; i++) {
    for (int j = 0; j < newM; j++) {
      for (int k = 0; k < 3; k++) {
        img4[i][j][k] = img[i + lt.i][j + lt.j][k];
      }
    }
  }

  *N = newN;
  *M = newM;

  return img4;
}

unsigned char ***task5(unsigned char ***img, int N, int M) {
  unsigned char ***img5 = alloc_img(N, M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      for (int k = 0; k < 3; k++) {
        img5[i][j][k] = img[i][j][k];
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int sum = 0;
      for (int k = 0; k < 3; k++) {
        sum += img5[i][j][k];
      }

      sum /= 3;
      for (int k = 0; k < 3; k++) {
        img5[i][j][k] = sum;
      }
    }
  }

  return img5;
}

unsigned char ***task6(unsigned char ***img, int N, int M) {
  if (N == M) {
    return img;
  }

  int new_size = (N > M) ? N : M;
  unsigned char ***img6 = alloc_img(new_size, new_size);
  int col1[3] = {0, 0, 0}, col2[3] = {0, 0, 0};

  if (M > N) {
    for (int j = 0; j < M; j++) {
      for (int k = 0; k < 3; k++) {
        col1[k] += img[0][j][k];
        col2[k] += img[N - 1][j][k];
      }
    }

    for (int k = 0; k < 3; k++) {
      col1[k] /= M;
      col2[k] /= M;
    }
  } else {
    for (int i = 0; i < N; i++) {
      for (int k = 0; k < 3; k++) {
        col1[k] += img[i][0][k];
        col2[k] += img[i][M - 1][k];
      }
    }

    for (int k = 0; k < 3; k++) {
      col1[k] /= N;
      col2[k] /= N;
    }
  }

  int auxi = abs(new_size - N) / 2;
  int auxj = abs(new_size - M) / 2;
  for (int i = 0; i < new_size; i++) {
    for (int j = 0; j < new_size; j++) {
      for (int k = 0; k < 3; k++) {
        if (i >= auxi && i < auxi + N && j >= auxj && j < auxj + M) {
          img6[i][j][k] = img[i - auxi][j - auxj][k];
        } else {
          if (M > N) {
            if (i < auxi) {
              img6[i][j][k] = col1[k];
            } else if (i >= auxi + N) {
              img6[i][j][k] = col2[k];
            }
          } else {
            if (j < auxj) {
              img6[i][j][k] = col1[k];
            } else if (j >= auxj + M) {
              img6[i][j][k] = col2[k];
            }
          }
        }
      }
    }
  }

  return img6;
}

void next(int *row, int *col, int *colour, int N, int M) {
  *colour += 1;
  if (*colour >= 3) {
    *colour = 0;
    *col += 1;
    if (*col >= M) {
      *col = 0;
      *row += 1;
      if (*row >= N) {
        printf("mesaj prea mare pentru encodare");
        exit(1);
      }
    }
  }
}

unsigned char ***encode(unsigned char ***img, int N, int M, char message[]) {
  unsigned char ***img_encode = alloc_img(N, M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      for (int k = 0; k < 3; k++) {
        img_encode[i][j][k] = img[i][j][k];
      }
    }
  }

  int len = strlen(message) + 1;
  int row = 0, col = 0, colour = 0;
  for (int i = 0; i < len; i++) {
    for (int j = 7; j >= 0; j--) {
      int bit = (message[i] >> j) & 1;
      img_encode[row][col][colour] = (img_encode[row][col][colour] & 254) | bit;
      next(&row, &col, &colour, N, M);
    }
  }

  return img_encode;
}

char *decode(unsigned char ***img_encode, int N, int M) {
  char *hidden = malloc(((N * M * 3) / 8) * sizeof(char));
  if (hidden == NULL) {
    exit(1);
  }

  int k = 0;
  int row = 0, col = 0, colour = 0;
  while (1) {
    int letter = 0;
    for (int i = 0; i < 8; i++) {
      int bit = img_encode[row][col][colour] & 1;
      letter = (letter << 1) | bit;
      next(&row, &col, &colour, N, M);
    }

    hidden[k++] = (char)letter;
    if (letter == 0) {
      break;
    }
  }

  return hidden;
}

int main(void) {
  int N, M;
  unsigned char ***img = bmp_read("flower.bmp", &N, &M);
  if (!img) {
    return 1;
  }

  printf("N = %d, M = %d\n", N, M);

  coord v[4];
  for (int i = 0; i < 4; i++) {
    scanf("%d%d", &v[i].i, &v[i].j);
  }
  int k;
  scanf("%d", &k);

  unsigned char ***img3 = task3(img, v[0], v[1], v[2], v[3], k, N, M);
  bmp_write("output3.bmp", img3, N, M);
  free_img(img3, N, M);

  int Nc = N, Mc = M;
  unsigned char ***img4 = task4(img, v[0], v[3], &Nc, &Mc);
  bmp_write("output4.bmp", img4, Nc, Mc);
  free_img(img4, Nc, Mc);

  unsigned char ***img5 = task5(img, N, M);
  bmp_write("output5.bmp", img5, N, M);
  free_img(img5, N, M);

  unsigned char ***img6 = task6(img, N, M);
  int new_size = (N > M) ? N : M;
  bmp_write("output6.bmp", img6, new_size, new_size);
  free_img(img6, new_size, new_size);

  char message[N * M];
  getchar();
  fgets(message, N * M, stdin);

  unsigned char ***img_encode = encode(img, N, M, message);
  char *hidden = decode(img_encode, N, M);
  printf("%s", hidden);

  bmp_write("output_crypt.bmp", img_encode, N, M);
  free_img(img_encode, N, M);
  free(hidden);

  free_img(img, N, M);

  return 0;
}