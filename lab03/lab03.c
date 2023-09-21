#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>  //pra evitar condição de corrida
#include <unistd.h>    //fork
#include <string.h>    //strcat: função que usamos para concatenar duas strings
#define SHMSIZE 27
int main() {
   int shmid;
   char *shm;

   if(fork() == 0) {
      shmid = shmget(2009, SHMSIZE, 0);
      shm = shmat(shmid, 0, 0);
      char *s = (char *) shm;
      *s = '\0';  
      
      int n;  //variavel que será usada
      printf("Digite um número para ser lido pelos processos que compartilharão memória: ");
      scanf("%d", &n);
      
      printf ("Child: %d\n",n);
      printf("Operação filho: %d * 2 = %d\n", n, (n*2));
      n = n * 2; 
      char number[20];
      sprintf(number, "%d", n);  // int para string
      strcat(s, number);  // concatena o numero na string
   
      shmdt(shm);
   }
   else {
      shmid = shmget(2009, SHMSIZE, 0666 | IPC_CREAT);
      shm = shmat(shmid, 0, 0);
      wait(NULL);
      printf ("Parent: %s\n",shm) ;
      int n = atoi(shm);
      printf("Operação pai: %d + 5 = %d", n, (n+5));
      shmdt(shm);
      shmctl(shmid, IPC_RMID, NULL);
   }
   return 0;
}
