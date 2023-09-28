#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int l = 10, c = 10;
int v[10];
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
  int m = mRank * loc;
  int n = (mRank + 1) * loc - 1;
  for (i = m; i <= n; i++) {
    r[i] = 0;
    for (j = 0; j < c; j++) {
      r[i] += (m[i][j]) * (v[j]);
    }
  }

  for (int i = 0; i < 10; i++){
    printf("R[%i]: ", i);
    printf("%d\n", r[i]);
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  
  for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("M[%i][%i]: ", i, j);
            printf("%d", m[i][j]);
        }
        printf("\n");
  }
 
  long thread;
  pthread_t *handle;
    
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

