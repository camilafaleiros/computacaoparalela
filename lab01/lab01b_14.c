#include <stdio.h>
#include <string.h>

void insert_char(char str[100]) {
    int length = 100;
    int position;
    char ch;

    printf("Inserir string de até 100 caractéres: ");
    scanf("%[^\n]%*c", str);
    printf("%s \n", str);

    printf("Inserir posição: ");
    scanf("%d", &position);
  
    if (position < 0 || position > length) {
        printf("Posição inválida.\n");
        return;
    }
    
    for (int i = length; i > position; i--) {
        str[i] = str[i - 1];
    }

    printf("Inserir um catacter: ");
    scanf(" %c", &ch);
    
    str[position] = ch;

    int new_length = strlen(str); 

    printf("\nNovo tamanho da string: %d", new_length);
    printf("\nString final: %s \n", str);
}

int main()
{
  char Str[100];
  insert_char(Str);
}

