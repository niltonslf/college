#include <stdio.h>
#include "./fatorial.h"

int main(void) {
  int fat = fatorial(5);
  printf("Fatorial de 5 é %d",fat);
  return 0;
}


double fatorial(int n){
  double vfat;

  if(n <= 1) {
    return (1);
  } else {
    printf("n agora vale: %d \n", n);
    vfat = n * fatorial(n-1);
  }
}