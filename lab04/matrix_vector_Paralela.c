#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int l = 10, c = 10;
int v[10] = {1, 2, 3, 4, 5, 2, 6, 3, 4, 3};;
int m[10][10] = {{1,1,2,2,3,3,4,4,5,5},
			  {6,6,7,7,8,8,9,9,10,10},
			  {1,1,2,2,3,3,4,4,5,5},
			  {6,6,7,7,8,8,9,9,10,10},
			  {1,1,2,2,3,3,4,4,5,5},
			  {6,6,7,7,8,8,9,9,10,10},
			  {1,1,2,2,3,3,4,4,5,5},
			  {6,6,7,7,8,8,9,9,10,10},
			  {1,1,2,2,3,3,4,4,5,5},
			  {6,6,7,7,8,8,9,9,10,10}};
int r[10];

int count_t;

void *createThread(void *rank) {
  long mRank = (long)rank;
  int i, j;
  int loc = l / count_t;
  int my_first_row = mRank * loc;
  int my_last_row = (mRank + 1) * loc - 1;
  for (i = my_first_row; i <= my_last_row; i++) {
    r[i] = 0;
    for (j = 0; j < c; j++) {
      r[i] += m[i][j] * v[j];
    }
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  
  for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("M[%i][%i]: ", i, j);
            printf("%d  ", m[i][j]);
        }
        printf("\n");
  }
 
  for (int i = 0; i < 10; i++){
    printf("V[%i]: ", i);
    printf("%d\n", v[i]);
  }
 
  long thread;
  pthread_t *handle;;
    
  count_t = strtol(argv[1], NULL, 10);
  handle = malloc(count_t * sizeof(pthread_t));
  for (thread = 0; thread < count_t; thread++) {
    pthread_create(&handle[thread], NULL, createThread,
                   (void *)thread);
  }
  for (thread = 0; thread < count_t; thread++) {
    pthread_join(handle[thread],
                 NULL);
  }

  free(handle);
}


