#include <stdio.h>
#include <string.h>
#define size 8

void find_char(char A[size])
{
  int i=0;
  int num = 0;
  char c;

  printf("Caractére desejado: ");
  scanf("%[^\n]%*c", &c);

  while (A[i] != c)
    {
      i++;
    }

  if (i < size)
    printf("N: %d", i);
  else
    printf("Não há o caractér desejado na palavra.");
}

int main()
{
  char str[10];
  printf("Digite uma palavra de até 10 caractéres: ");
  scanf("%[^\n]%*c", str);
  printf("%a \n", str);
  find_char(str);
}
