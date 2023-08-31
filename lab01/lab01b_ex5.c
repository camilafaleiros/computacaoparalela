#include <stdio.h>

int main(void) {
  int matriz[2][2];
  
  matriz[0][0] = 1;
  matriz[0][1] = 10;
  matriz[1][0] = 100;
  matriz[1][1] = 1000;

  int multiplicador = 5;
  
  for ( int i=0; i<2; i++ ) 
  {
    for ( int j=0; j<2; j++ )
    {
      int numero = matriz[i][j];
      matriz[i][j] = numero*multiplicador;
      printf("%d ",matriz[i][j]);
    }
    printf("\n");
  }
  return 0;
}

