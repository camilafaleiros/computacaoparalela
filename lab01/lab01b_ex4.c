#include <stdio.h>

int main(void) {
  char nome1[15] = "Andre";
  char nome2[15] = "Amanda";

  //verifica primeira e segunda letra
  if (nome1[0] == nome2[0]){
      if (nome1[1] < nome2[1]){
        printf("%s %s", nome1, nome2);
      }
      else
        printf("%s %s", nome2, nome1); 
      }
    
  else if (nome1[0] < nome2[0]){
    printf("%s %s", nome1, nome2);
  }
    
  else
    printf("%s %s", nome2, nome1); 
  return 0;
}
