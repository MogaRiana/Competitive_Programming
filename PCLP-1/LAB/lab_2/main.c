#include <stdio.h>

int main(){
  int caz;
  scanf("%d",&caz);

  switch (caz)
  {
  case 1:{
    int n;
    scanf("%d", &n);

    if(n % 2 == 0){
      printf("par\n");
    }else{
      printf("impar\n");
    }

    if(n & 1){
      printf("impar\n");
    }else{
      printf("par\n");
    }
    
    break;
  }
  
  case 2:{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    if(a > 0 && b > 0 && c > 0 && a + b >= c && a + c >= b && b + c >= a){
      printf("DA");
    }else{
      printf("NU");
    }
    
    break;
  }

  case 3:{
    short int a = 45;
    int b = 50;
    long int c = 60;

    printf("%ld\n", sizeof(a));
    printf("%ld\n", sizeof(b));
    printf("%ld\n", sizeof(c));
    printf("\n");
    printf("%ld\n", sizeof(short int));
    printf("%ld\n", sizeof(int));
    printf("%ld\n", sizeof(long int));
    
    break;    
  } 

  case 4:{
    int n;
    scanf("%d", &n);

    printf("n = %d\n", n);
    printf("\n");
    printf("OUT:");
    while(n){
      printf("\n");
      for(int i = 0; i < n; i++){
        printf("*");
      }
      n--;
    }

    break;
  }

  case 5:{
    int n;
    scanf("%d", &n);

    int rez = 1;
    for(int i = 1; i <= n; i++){
      rez = rez * i;
    }

    printf("%d\n", rez);

    break;
  }

  case 6:{
    int n, cn;
    scanf("%d", &n);
    
    cn = n;
    int inv = 0;
    while(cn){
      inv = inv * 10 + cn % 10;
      cn = cn / 10;
    }

    if(inv == n){
      printf("palindrom\n");
    }else{
      printf("nu e palindrom\n");
    }

    break;
  }

  case 7:{
    int n, k = 0;

    while(scanf("%d", &n)){
      printf("OUT: ");
      if( n < 0){
        printf("S-au gasit %d numere prime.", k);
        break;
      }

      int ok = 1;
      for(int i = 2; i < n; i++){
        if(n % i == 0){
          ok = 0;
          printf("%d ", i);
        }
      }

      if(ok == 1){
        printf("PRIM");
        k++;
      }

      printf("\n");
    }

    break;
  }

  default:
    break;
  }

  return 0;
}