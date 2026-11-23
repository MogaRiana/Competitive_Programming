#include <limits.h>
#include <stdio.h>

#define N 100

int read_array(int v[]){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%d", &v[i]);
  }

  return n;
}

void print_array(int n, int v[]){
  for(int i = 0; i < n; i++){
    printf("%d ", v[i]);
  }
  printf("\n");

}

int sum_array(int n, int v[]){
  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += v[i];
  }

  return sum;
}

int min_array(int n, int v[]){
  int res = INT_MAX;
  for(int i = 0; i < n; i++){
    if(v[i] < res){
      res = v[i];
    }
  }


  return res;
}

int posmax_array(int n, int v[]){
  int res = -INT_MAX;
  int pos = -1;
  for(int i = 0; i < n; i++){
    if(v[i] > res){
      res = v[i];
      pos = i;
    }
  }

  return pos;
}

double avg_array(int n, int v[]){
  return (double)(sum_array(n, v)) / (double)(n);
}

int find_array(int n, int v[], int target){
  for(int i = 0; i < n; i++){
    if(v[i] == target){
      return i;
    }
  }
  
  return -1;
}

int main(){
  int v[N];
  int n = read_array(v);

  printf("sum: %d\n", sum_array(n, v));
  printf("min: %d\n", min_array(n, v));
  printf("posmax: %d\n", posmax_array(n, v));
  printf("avg: %f\n", avg_array(n, v));
  printf("find 30: %d\n", find_array(n, v, 30));
  printf("find 4: %d\n", find_array(n, v, 4));
  printf("find 13: %d\n", find_array(n, v, 13));

  return 0;
}