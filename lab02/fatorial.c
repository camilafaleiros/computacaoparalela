#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
  int num = 6, i;
  int pip[2];
  int child = 1;

  printf("Fatorial do valor: %d\n", num);

  //criar pipe para ligar o pai ao filho  
  if (pipe(pip) == -1) {
    printf("Erro");
    return 0;
  }
  
  pid_t child_ID = fork();

  if (child_ID == -1) {
    printf("Erro");
    exit(EXIT_FAILURE);
    
  }

  //se o child for criado, realizar metade da operaÃ§Ã£o nele
  else if (child_ID == 0) {
    close(pip[0]);
    for (i = 1; i <= num/2; i++){
      child = child * i;
    }
    write(pip[1], &child, sizeof(int));
    close(pip[1]);
  }

  //realizar o resto da operaÃ§Ã£o no pai re retornar o resultado
  else {
    close(pip[1]);
    int ans;
    read(pip[0], &ans, sizeof(int));
    for (i = (num/2)+1; i <= num; i++){
      ans = ans * i;
    }
    close(pip[0]);
    wait(NULL);
    printf("Resultado: %d", ans);
  }
  return 0;
}

