#include <stdio.h>
#include <string.h>

void remove_char(char Str[100])
{
  int length = 100;
  int position;

  printf("Inserir string de até 100 caractéres: ");
  scanf("%[^\n]%*c", Str);
  printf("String inicial: %s \n", Str);

  printf("Digite a posição: ");
  scanf("%d", &position);
    
  if (position < 0 || position >= length) {
      printf("Posição inválida.\n");
      return;
  }
    
  for (int i = position; i < length - 1; i++) {
     Str[i] = Str[i + 1];
  }
    
  Str[length - 1] = '\0';

  int new_length = strlen(Str);

  printf("Novo tamanho da string: %d", new_length);
  printf("\nString final: %s \n", Str);
}

int main()
{
  char Str[100];

  remove_char(Str);
}
