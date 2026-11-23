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

int find_array(int n, int v[], int target){
  int l = 0, r = n;
  while(l <= r){
    int mid = r + (r-l)/2;
    if(v[mid] == target){
      return mid;
    }else if(v[mid] < target){
      l = mid + 1;
    }else{
      r = mid - 1;
    }
  }
  
  return -1;
}

int main(){
  int v[N];
  int n = read_array(v);

  printf("%d\n", find_array(n, v, 10));

  return 0;
}