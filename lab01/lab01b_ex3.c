#include <stdio.h>

//fazendo com valores fixos ao invés de input por que o prof pediu!!
int main(void) {
  int maximo = 9;
  for (int i = maximo; i > 0; i--){
    for (int j = 1; j <= i; j++){
      printf("%d", j);
    }
    printf("\n");
  }
  return 0;
}
