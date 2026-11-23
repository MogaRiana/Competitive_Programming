#include <stdio.h>
#include <strings.h>

void slv1(){
  int *a = 0x00;
  int *b = a;
  printf("*a = %p\n", a);
  ++a;

  printf("*a = %p\n*b = %p", a, b);
  // printf("a = %d\n b = %d", *a, *b);
}

void slv2(){
  int n;
  scanf("%d", &n);
  int v[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &v[i]);
  }

  for(int i = 0; i < n; i++){
    printf("v[%d] = %d, &v[%d] = %p\n", i, v[i], i, &v[i]);
  }
}

void slv3(){
  int n = 5, m = 6;
  double a[n][m];
  a[2][3] = 12.1;

  double *p = *(a + 2) + 3;
  printf("&p = %p\n&a[2][3] = %p", p, &a[2][3]);
  
  *p = 15.3;
  printf("*p = %lf\na[2][3] = %lf", *p, a[2][3]);

}

int main(){
  printf("ex 1.1\n");
  slv1();
  printf("\n");

  printf("ex 1.2\n");
  slv2();
  printf("\n");

  printf("ex 1.3\n");
  slv3();

  return 0;
}