#include <stdio.h>

int main(void) {
  int matriz[2][2];
  
  matriz[0][0] = 1;
  matriz[0][1] = 10;
  matriz[1][0] = 100;
  matriz[1][1] = 1000;

  int linha;
  
  for ( int i=0; i<2; i++ ) 
  {
    for ( int j=0; j<2; j++ )
    {
      int aux = matriz[0][0];
      if (matriz[i][j] < aux)
      {
        aux = matriz[i][j];
        linha = i;
      }
    }
  }

  printf("A linha que contém o menor valor da matriz é a: %d", linha);
  return 0;
}
