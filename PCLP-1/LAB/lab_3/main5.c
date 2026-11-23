#include <stdio.h>

int power_log(int a, int b){
  if(b == 0){
    return 1;
  }
  if(b == 1){
    return a;
  }

  if(b % 2 == 0){
    int r = power_log(a, b / 2);
    return r * r;
  }
  return power_log(a, b - 1) * a;
}

int count_digits(int n){
  if(n == 0){
    return 1;
  }
  if(n < 10){
    return 1;
  }

  return 1 + count_digits(n / 10);
}

int reverse_number(int n){
  if(n < 10){
    return n;
  }

  int c = count_digits(n);
  int p = power_log(10, c - 1);

  return n % 10 * p + reverse_number(n / 10);
}

int is_palindrome(int n){
  return (n == reverse_number(n)) ? 1 : 0;
}

int next_palindrom(int n){
  if(n == reverse_number(n)){
    return n;
  }

  return next_palindrom(n + 1);
}

int main(){
  int n;
  scanf("%d", &n);
  printf("%d", next_palindrom(n));

  return 0;
}