 #include <stdio.h>


//fazendo com valores fixos ao invés de input por que o prof pediu!!
int main(void) {
  int N1 = 6;
  int N2 = 9;
  int N3 = 4;
  int ME = 10;

  float MA;
  MA = (N1 + N2*2 + N3*3 + ME);
  MA = MA/7;

  if (MA >= 9)
    printf("Aluno nota A");
    
  else if (MA >= 7.5 && MA < 9)
    printf("Aluno nota B");
    
  else if (MA >= 6 && MA < 7.5)
    printf("Aluno nota C");
    
  else if (MA >= 4 && MA < 6)
    printf("Aluno nota D");
    
  else if (MA < 4)
    printf("Aluno nota E");
  
  return 0;
}
